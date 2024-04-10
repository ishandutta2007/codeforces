//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
vector<int> val,aa,bb;
vector<int> both,alice,bob,proc;

int pos[200005];

struct node{
	int s,e,m;
	int v,num;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			v=l->v+r->v;
			num=l->num+r->num;
		}
		else{
			v=val[proc[s]];
			num=1;
		}
	}
	
	void update(int i,int j){
		if (s==e){
			num=j;
			
			if (num==0) v=0;
			else v=val[proc[s]];
		}
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			v=l->v+r->v;
			num=l->num+r->num;
		}
	}
	
	int query(int i){
		if (i==0) return 0;
		if (num==i) return v;
		if (i<=l->num) return l->query(i);
		else{
			int ans=l->v;
			i-=l->num;
			if (i) ans+=r->query(i);
			
			return ans;
		}
	}
}*root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	rep(x,0,n){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		
		val.push_back(t1);
		aa.push_back(t2);
		bb.push_back(t3);
		
		if (aa[x] && bb[x]) both.push_back(x);
		else if (aa[x]) alice.push_back(x);
		else if (bb[x]) bob.push_back(x);
		proc.push_back(x);
	}
	
	sort(all(both),[](int i,int j){return val[i]<val[j];});
	sort(all(alice),[](int i,int j){return val[i]<val[j];});
	sort(all(bob),[](int i,int j){return val[i]<val[j];});
	sort(all(proc),[](int i,int j){return val[i]<val[j];});
	
	root=new node(0,n-1);
	
	rep(x,0,n) pos[proc[x]]=x;
	
	ll ans=1e18;
	int idx=-1;
	
	int curr=0;
	
	rep(x,0,min(k,sz(both))){
		root->update(pos[both[x]],0);
		curr+=val[both[x]];	
	}
	
	rep(x,k,2*k+1){
		int bsz=2*k-x;
		int inz=x-k;
		int extra=m-bsz-inz*2;
		if (bsz<=sz(both)){
			//cout<<bsz<<" "<<inz<<" "<<extra<<endl;
			//cout<<curr<<endl;
			
			if (0<=extra && extra<=root->num){
				//cout<<root->query(extra)<<endl;
				int vval=curr+root->query(extra);
				
				if (ans>vval){
					ans=vval;
					idx=x;
				}
			}
			
			if (bsz){
				root->update(pos[both[bsz-1]],1);
				curr-=val[both[bsz-1]];
			}
		}
		
		if (inz>=sz(alice) || inz>=sz(bob)) break;
		curr+=val[alice[inz]]+val[bob[inz]];
		root->update(pos[alice[inz]],0);
		root->update(pos[bob[inz]],0);
	}
	
	if (ans==1e18){
		cout<<"-1"<<endl;
		return 0;
	}
	
	cout<<ans<<endl;
	int bsz=2*k-idx;
	int inz=idx-k;
	
	set<int> s;
	rep(x,0,bsz) s.insert(both[x]);
	rep(x,0,inz) s.insert(alice[x]),s.insert(bob[x]);
	
	for (auto &it:proc){
		if (sz(s)==m) break;
		
		s.insert(it);
	}
	
	for (auto &it:s) cout<<it+1<<" ";
}