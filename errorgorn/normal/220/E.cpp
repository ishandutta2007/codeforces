/*













*/

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

const int INF=1e5+5;

ll n,k;
ll arr[100005];

struct node{
  int s,e,m;
  long long val=0;
  node *l,*r;
  node(int _s,int _e){
    s=_s,e=_e,m=(s+e)>>1;
    if (s!=e){
      l=new node(s,m);
      r=new node(m+1,e);
    }
  }
  long long query(int i,int j){
    if (i==s && j==e) return val;
    else if (j<=m) return l->query(i,j);
    else if (m<i) return r->query(i,j);
    else return l->query(i,m)+r->query(m+1,j);
  }
  void update(int i, long long k){
    if (s==e){
      val+=k;
    }
    else{
        if (i<=m) l->update(i,k);
        else r->update(i,k);
        val=l->val+r->val;
    }
  }
}*before=new node(0,INF),*after=new node(0,INF);

vector<int> uu;
map<int,int> m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	ll inv=0;
	rep(x,0,n){
		cin>>arr[x];
		uu.push_back(arr[x]);
	}
	
	sort(all(uu));
	uu.erase(unique(all(uu)),uu.end());
	
	rep(x,0,sz(uu)) m[uu[x]]=x+1;
	rep(x,0,n) arr[x]=m[arr[x]];
	
	rep(x,0,n){
		after->update(arr[x],1);
		inv+=after->query(arr[x]+1,INF);
	}
	
	int l=-1;
	ll ans=0;
	rep(x,1,n){
		after->update(arr[x-1],-1);
		inv-=after->query(0,arr[x-1]-1);
		inv-=before->query(arr[x-1]+1,INF);
	
		while (l<x && inv<=k){
			l++;
			before->update(arr[l],1);
			inv+=after->query(0,arr[l]-1);
			inv+=before->query(arr[l]+1,INF);
		}
		
		//cout<<l<<" "<<x<<" "<<inv<<endl;
		
		ans+=max(l,0);
	}
	
	cout<<ans<<endl;
}