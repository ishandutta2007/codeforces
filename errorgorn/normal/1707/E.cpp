//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int,int>
#define i4 tuple<int,int,int,int>
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

const int INF=1e9;

int n,q;
int arr[100005];

//ID of shit, so we can simply pass the ID into the segment tree
int l[200005];
int r[200005];
int w[200005];

int ql[100005];
int qr[100005];
int ans[100005];

struct node{
	int s,e,m;
	int mx,mn;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			mn=min(l->mn,r->mn);
			mx=max(l->mx,r->mx);
		}
		else{
			mn=mx=arr[s];
		}
	}
	
	int query_mn(int i,int j){
		if (s==i && e==j) return mn;
		else if (j<=m) return l->query_mn(i,j);
		else if (m<i) return r->query_mn(i,j);
		else return min(l->query_mn(i,m),r->query_mn(m+1,j));
	}
	
	int query_mx(int i,int j){
		if (s==i && e==j) return mx;
		else if (j<=m) return l->query_mx(i,j);
		else if (m<i) return r->query_mx(i,j);
		else return max(l->query_mx(i,m),r->query_mx(m+1,j));
	} 
	
	int findl_mn(int i,int k){
		if (mn>k) return -1;
		if (s==e) return s;
		if (m<i) return r->findl_mn(i,k);
		else{
			int temp=l->findl_mn(i,k);
			if (temp!=-1) return temp;
			else return r->findl_mn(m+1,k);
		}
	}
	
	int findl_mx(int i,int k){
		if (mx<k) return -1;
		if (s==e) return s;
		if (m<i) return r->findl_mx(i,k);
		else{
			int temp=l->findl_mx(i,k);
			if (temp!=-1) return temp;
			else return r->findl_mx(m+1,k);
		}
	}
	
	int findr_mn(int i,int k){
		if (mn>k) return -1;
		if (s==e) return s;
		if (i<=m) return l->findr_mn(i,k);
		else{
			int temp=r->findr_mn(i,k);
			if (temp!=-1) return temp;
			else return l->findr_mn(m,k);
		}
	}
	
	int findr_mx(int i,int k){
		if (mx<k) return -1;
		if (s==e) return s;
		if (i<=m) return l->findr_mx(i,k);
		else{
			int temp=r->findr_mx(i,k);
			if (temp!=-1) return temp;
			else return l->findr_mx(m,k);
		}
	}
} *root;

int CURR=0;

struct node2{
	int s,e,m;
	vector<ii> v; //(r,val)
	int idx=0;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,ii val){ //larger value should be inserted later
		if (v.empty() || v.back().fi>val.fi){
			if (!v.empty() && w[v.back().se]==w[val.se]) v.pob();
			v.pub(val);
		}
		
		if (s==e) return;
		if (i<=m) l->update(i,val);
		else r->update(i,val);
	}
	
	bool has(int i,int j){
		if (s==i) return !v.empty() && v.back().fi<=j;
		else if (m<i) return r->has(i,j);
		else return l->has(i,j)|r->has(m+1,j);
	}
	
	int hasCURR(int i,int j){
		if (s==i){
			while (idx<sz(v) && w[v[idx].se]<CURR) idx++;
			if (idx<sz(v) && w[v[idx].se]==CURR && v[idx].fi<=j) return v[idx].se;
			else return INF;
		}
		else if (m<i) return r->hasCURR(i,j);
		else return min(l->hasCURR(i,j),r->hasCURR(m+1,j));
	}
} *root2=new node2(0,100005);

struct node3{
	int s,e,m;
	priority_queue<i4,vector<i4>,greater<i4> > pq;
	ii mn;
	node3 *l,*r;
	
	node3(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		mn={1e9,s};
		
		if (s!=e){
			l=new node3(s,m);
			r=new node3(m+1,e);
		}
	}
	
	void update(int i,i4 k){
		if (s==e){
			pq.push(k);
			mn.fi=get<0>(pq.top());
		}
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			mn=min(l->mn,r->mn);
		}
	}
	
	i4 pop(int i){ //it also deletes
		i4 res;
		if (s==e){
			res=pq.top(); pq.pop();
			if (pq.empty()) mn.fi=1e9;
			else mn.fi=get<0>(pq.top());
		}
		else{
			if (i<=m) res=l->pop(i);
			else res=r->pop(i);
			mn=min(l->mn,r->mn);
		}
		
		return res;
	}
	
	ii query(int i){
		if (s==i) return mn;
		else if (m<i) return r->query(i);
		else return min(l->query(i),r->query(m+1));
	}
} *root3=new node3(0,100005);

struct node4{
	int s,e,m;
	int val=1e9;
	node4 *l,*r;
	
	node4 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node4(s,m);
			r=new node4(m+1,e);
		}
	}
	
	void update(int i,int k){
		val=min(val,k);
		
		if (s==e) return;
		if (i<=m) l->update(i,k);
		else r->update(i,k);
	}
	
	int query(int i){
		if (s==i) return val;
		else if (m<i) return r->query(i);
		else return min(l->query(i),r->query(m+1));
	}
} *root4=new node4(0,100005);

set<ii> s;
set<i4> ss;
deque<ii> dq;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	root=new node(1,n);
	
	s.insert({0,0});
	s.insert({n+1,n+1});
	
	dq.puf({1,n});
	
	int IDX=0;
	while (!dq.empty()){
		int a,b; tie(a,b)=dq.front(); dq.pof();
		if (root2->has(a,b)) continue;
		
		int weight;
		if (ii(a,b)==ii(1,n)) weight=0;
		else{
			int mn,mx,temp; 
			tie(mn,mx)=ii(root->query_mn(a,b),root->query_mx(a,b));
			while ((temp=root2->hasCURR(mn,mx))==INF) CURR++;
			weight=CURR+1;
			tie(mn,mx)=ii(l[temp],r[temp]);
			b=max(root->findl_mn(a,mn),root->findl_mx(a,mx));
			a=min(root->findr_mn(b,mn),root->findr_mx(b,mx));
		}
		
		l[IDX]=a,r[IDX]=b,w[IDX]=weight;
		root2->update(a,{b,IDX});
		IDX++;
		
		int a2,b2,mn,mx,temp;
		
		auto it=s.insert({a,b}).fi;
		while (b<=(*prev(it)).se) s.erase(prev(it));
		tie(a2,b2)=ii((*prev(it)).fi+1,b-1);
		if (a2<=b2){
			tie(mn,mx)=ii(root->query_mn(a2,b2),root->query_mx(a2,b2));
			if (!root2->has(mn,mx)) root3->update(mx,{mn,mx,a2,b2});
			else{
				if (root2->hasCURR(mn,mx)!=1e9) dq.puf({a2,b2});
				else dq.pub({a2,b2});
			}
		}
		
		tie(a2,b2)=ii(a+1,(*next(it)).se-1);
		if (a2<=b2){
			tie(mn,mx)=ii(root->query_mn(a2,b2),root->query_mx(a2,b2));
			if (!root2->has(mn,mx)) root3->update(mx,{mn,mx,a2,b2});
			else{
				if (root2->hasCURR(mn,mx)!=1e9) dq.puf({a2,b2});
				else dq.pub({a2,b2});
			}
		}
		
		while (root3->query(b).fi<=a){
			auto temp=root3->pop(root3->query(b).se);
			dq.pub({get<2>(temp),get<3>(temp)});
		}
	}
	
	rep(x,0,q) cin>>ql[x]>>qr[x];
	
	vector<int> idx1,idx2;
	rep(x,0,q) idx1.pub(x);
	rep(x,0,IDX) idx2.pub(x);
	
	sort(all(idx1),[](int i,int j){
		return qr[i]<qr[j];
	});
	sort(all(idx2),[](int i,int j){
		return r[i]>r[j];
	});
	
	rep(x,0,q){
		while (!idx2.empty() && r[idx2.back()]<=qr[idx1[x]]){
			root4->update(l[idx2.back()],w[idx2.back()]);
			idx2.pob();
		}
		
		int val=root4->query(ql[idx1[x]]);
		
		if (val==INF) ans[idx1[x]]=-1;
		else ans[idx1[x]]=val;
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}