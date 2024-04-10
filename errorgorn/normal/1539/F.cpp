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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];

const int INF=1e9;

struct node{
	int s,e,m;
	int mn=INF,mx=-INF,lazy=0;
	node *l,*r;
	
	node (int _s,int _e,int par){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m,par);
			r=new node(m+1,e,par);
			mn=min(l->mn,r->mn);
			mx=max(l->mx,r->mx);
		}
		else{
			if (par==0 && s%2==0){
				mn=-s,mx=-s;
			}
			if (par==1 && s%2!=0){
				mn=-s,mx=-s;
			}
		}
	}
	
	void propo(){
		if (lazy){
			mn+=lazy;
			mx+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,ll k){
		if (s==i && e==j){
			lazy+=k;
		}
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			mn=min(l->mn,r->mn);
			mx=max(l->mx,r->mx);
		}
	}
	
	ll query1(int i,int j){
		propo();
		if (s==i && e==j){
			return mn;
		}
		else if (j<=m) return l->query1(i,j);
		else if (m<i) return r->query1(i,j);
		else return min(l->query1(i,m),r->query1(m+1,j));
	}
	ll query2(int i,int j){
		propo();
		if (s==i && e==j){
			return mx;
		}
		else if (j<=m) return l->query2(i,j);
		else if (m<i) return r->query2(i,j);
		else return max(l->query2(i,m),r->query2(m+1,j));
	}
} *even,*odd;

int ans[2][200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(zzz,0,2){
		even=new node(-1,200005,0),odd=new node(-1,200005,1);
		
		vector<int> proc;
		rep(x,0,n) proc.pub(x);
		sort(all(proc),[](int i,int j){
			return arr[i]<arr[j];
		});
		
		int idx=0;
		
		for (auto &it:proc){
			while (idx!=sz(proc) && arr[proc[idx]]<=arr[it]){
				even->update(proc[idx],200005,2);
				odd->update(proc[idx],200005,2);
				
				idx++;
			}
			
			ll ef,of,eb,ob;
			
			if (it%2==0){
				int temp=even->query1(it,it);
				ef=temp-even->query1(-1,it);
				of=temp-odd->query1(-1,it);
				eb=even->query2(it,200005)-temp;
				ob=odd->query2(it,200005)-temp;
			}
			else{
				int temp=odd->query1(it,it);
				ef=temp-odd->query1(-1,it);
				of=temp-even->query1(-1,it);
				eb=odd->query2(it,200005)-temp;
				ob=even->query2(it,200005)-temp;
			}
			
			if (zzz==0){
				ans[zzz][it]=max(
					max(ef+eb,of+ob)-2,
					max(ef+ob,of+eb)-1
				);
			}
			else{
				ans[zzz][it]=max(
					max(ef+eb,of+ob),
					max(ef+ob,of+eb)-1
				);
			}
			
			//cout<<it<<" "<<ef<<" "<<of<<" "<<eb<<" "<<ob<<endl;
		}
		
		reverse(arr,arr+n);
		rep(x,0,n) arr[x]=n-arr[x];
	}
	
	//rep(x,0,n) cout<<ans[0][x]<<" "; cout<<endl;
	//rep(x,n,0) cout<<ans[1][x]<<" "; cout<<endl;
	
	rep(x,0,n) cout<<max(ans[0][x],ans[1][n-x-1])/2<<" "; cout<<endl;
}