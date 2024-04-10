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

struct Q{
	int l,r,idx;
	
	Q(int a,int b,int c){
		l=a,r=b,idx=c;
	}
};

int n,q;
int arr[500005];
int ans[500005];

ii occ[500005];

vector<Q> queries;

struct node{
	int s,e,m;
	vector<int> st;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void ins(int i,int j,ll k){
		if (s==i && e==j) st.push_back(k);
		else if (j<=m) l->ins(i,j,k);
		else if (m<i) r->ins(i,j,k);
		else l->ins(i,m,k),r->ins(m+1,j,k);
	}
	
	int get(int i){
		while (!st.empty()){
			if (e<occ[st.back()].se) break;
			st.pop_back();
		}
		if (!st.empty()) return st.back();
		if (s==e) return 0;
		else if (i<=m) return l->get(i);
		else return r->get(i);
	}
}*root=new node(0,500005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n){
		cin>>arr[x];
	}
	
	cin>>q;
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--,b--;
		
		queries.push_back(Q(a,b,x));
	}
	
	sort(all(queries),[](Q &i,Q &j){
		return i.l>j.l;
	});
	
	int curr=n;
	for (auto &it:queries){
		while (curr>it.l){
			curr--;
			
			if (occ[arr[curr]]==ii(0,0)){
				root->ins(curr,n-1,arr[curr]);
				occ[arr[curr]]=ii(curr,n);
			}
			else{
				root->ins(curr,occ[arr[curr]].fi-1,arr[curr]);
				occ[arr[curr]]=ii(curr,occ[arr[curr]].fi);
			}
		}
		
		ans[it.idx]=root->get(it.r);
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}