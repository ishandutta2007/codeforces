#include <bits/stdc++.h>
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

int n,m;

int tree[1000005][26];

int arr[1000005];
bool marked[1000005];
int cnt[1000005];

ii w[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(tree,-1,sizeof(tree));
	
	cin>>n;
	
	int a;char b;
	rep(x,1,n+1){
		cin>>a>>b;
		tree[a][b-'a']=x;
	}
	
	cin>>m;
	rep(x,0,m){
		cin>>arr[x];
		marked[arr[x]]=true;
	}
	
	rep(x,n+1,0){
		rep(y,0,26) if (tree[x][y]!=-1) cnt[x]+=cnt[tree[x][y]];
		if (marked[x]) cnt[x]++;
	}
	
	
	rep(x,0,n+1){
		if (marked[x]) w[x].fi=min(w[x].fi,w[x].se+1);
		
		int curr=marked[x];
		rep(y,0,26) if (tree[x][y]!=-1){
			w[tree[x][y]]=ii(w[x].fi+1,min(w[x].fi,w[x].se)+curr);
			curr+=cnt[tree[x][y]];
		}
		
		//cout<<x<<" "<<w[x].fi<<" "<<w[x].se<<endl;
	}
	
	rep(x,0,m){
		cout<<w[arr[x]].fi<<" ";
	}
}