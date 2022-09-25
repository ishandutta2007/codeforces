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

int n,m,k;
ii arr[100005];
vector<int> v;
vector<int> val[200005];

int cnt[2][300];
vector<int> c1,c2;

int temp[300];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	rep(x,0,n){
		cin>>arr[x].fi>>arr[x].se;
		v.push_back(arr[x].fi-1);
		v.push_back(arr[x].se);
	}
	
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	
	rep(x,0,n){
		int iter=lower_bound(all(v),arr[x].fi)-v.begin();
		
		while (iter<sz(v) && v[iter]<=arr[x].se){
			val[iter++].push_back(x);
		}
	}
	
	v.push_back(1000000005);
	
	/*
	rep(x,0,sz(v)){
		for (auto &it:val[x]) cout<<it<<" ";
		cout<<endl;
	}
	*/
	
	int a=0,b=1;
	rep(x,1,sz(v)){
		c1.clear();
		c2.clear();
		memset(temp,0,sizeof(temp));
		memset(cnt[b],0,sizeof(cnt[b]));
		
		int i=0,j=0;
		while (i<sz(val[x-1]) && j<sz(val[x])){
			if (val[x-1][i]<val[x][j]) i++;
			else if (val[x-1][i]>val[x][j]) j++;
			else{
				c1.push_back(i);
				c2.push_back(j);
				i++,j++;
			}
		}
		
		rep(y,0,1<<sz(val[x-1])){
			int bm=0;
			rep(bit,0,sz(c1)) if (y&(1<<c1[bit])) bm|=(1<<bit);
			temp[bm]=max(temp[bm],cnt[a][y]);
		}
		
		rep(y,0,1<<sz(val[x])){
			int bm=0;
			rep(bit,0,sz(c2)) if (y&(1<<c2[bit])) bm|=(1<<bit);
			cnt[b][y]=max(cnt[b][y],temp[bm]);
			
			if (__builtin_parity(y)) cnt[b][y]+=v[x]-v[x-1];
			
			//cout<<x<<" "<<y<<" "<<cnt[b][y]<<endl;
		}
		
		swap(a,b);
	}
	
	cout<<cnt[a][0];
}