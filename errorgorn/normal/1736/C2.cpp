//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct dat{
	int l,r;
	int vl,vr;
	int ans;
	
	dat(int pos,int val){
		l=r=pos;
		vl=vr=val;
		ans=0;
	}
};

dat merge(dat a,dat b){
	dat res={0,0};
	res.l=a.l,res.vl=a.vl;
	res.r=b.r,res.vr=b.vr;
	res.ans=a.ans+b.ans+(b.vl-a.vr)*b.l;
	return res;
}

struct node{
	int s,e,m;
	dat val={0,0};
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,dat k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			val=merge(l->val,r->val);
		}
	}
	
	dat query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return merge(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,200005);

int n,q;
int arr[200005];
int id[200005];

vector<int> idx;
vector<vector<int> > vidx;
vector<node*> ridx;

int getAns(){
	vector<ii> v;
	rep(x,1,n+1) v.pub({arr[x],x-1});
	
	sort(all(v));
	
	int mn=n;
	int ans=0;
	rep(x,n+1,1){
		while (!v.empty() && v.back().fi==x) mn=min(mn,v.back().se),v.pob();
		ans+=mn-x+1;
	}
	
	return ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) arr[x]=x-arr[x];
	arr[0]=0,arr[n+1]=n;
	
	//rep(x,0,n+2) cout<<arr[x]<<" "; cout<<endl;
	
	rep(x,n+2,0){
		while (!idx.empty() && arr[idx.back()]<=arr[x]) idx.pob();
		idx.pub(x);
	}
	
	reverse(all(idx));
	rep(x,0,sz(idx)){
		int pos=idx[x];
		root->update(x,{pos,arr[pos]});
	}
	
	rep(x,0,sz(idx)-1){
		rep(y,idx[x],idx[x+1]) id[y]=x;
		
		vector<int> idx2;
		rep(y,idx[x+1],idx[x]+1){
			while (!idx2.empty() && arr[idx2.back()]<=arr[y]) idx2.pob();
			idx2.pub(y);
		}
		int temp=x?arr[idx[x-1]]:0;
		while (!idx2.empty() && arr[idx2.back()]<=temp) idx2.pob();
		
		reverse(all(idx2));
		// cout<<"debug: "<<idx[x]<<" "<<idx[x+1]<<endl;
		// for (auto it:idx2) cout<<it<<" "; cout<<endl;
		vidx.pub(idx2);
		node *root2=new node(0,sz(idx2));
		rep(x,0,sz(idx2)){
			int pos=idx2[x];
			root2->update(x,{pos,arr[pos]});
		}
		ridx.pub(root2);
	}
	
	//rep(x,0,sz(idx)) cout<<idx[x]<<" "<<arr[idx[x]]<<endl;
	
	cin>>q;
	while (q--){
		int a,b;
		cin>>a>>b;
		
		int t1=arr[a];
		
		arr[a]=a-b;
		
		//rep(x,0,n+2) cout<<arr[x]<<" "; cout<<endl;
		
		int lp=id[a],lpos=idx[id[a]];
		dat t2=root->query(lp,lp);
		dat val={0,0};
		int mx;
		if (lpos==a){
			//for (auto it:vidx[lp]) cout<<it<<" "; cout<<endl;
			
			mx=max(arr[idx[lp-1]],arr[a]);
			val=root->query(0,lp-1);
			if (arr[idx[lp-1]]<arr[a]) val=merge(val,{a,arr[a]});
			
			int lo=-1,hi=sz(vidx[lp]),mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				if (mx<arr[vidx[lp][mi]]) hi=mi;
				else lo=mi;
			}
			
			if (hi!=sz(vidx[lp])){
				val=merge(val,ridx[lp]->query(hi,sz(vidx[lp])-1));
				mx=arr[vidx[lp].back()];
			}
		}
		else{
			if (arr[lpos]<arr[a]) root->update(lp,merge({lpos,arr[lpos]},{a,arr[a]}));
			
			mx=max(arr[lpos],arr[a]);
			val=root->query(0,lp);
		}
		
		int lo=-1,hi=sz(idx)-1,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (mx<arr[idx[mi]]) hi=mi;
			else lo=mi;
		}
		
		int ans=merge(val,root->query(hi,sz(idx)-1)).ans;
		cout<<ans-n*(n+1)/2<<endl;
		
		arr[a]=t1;
		root->update(lp,t2);
	}
}