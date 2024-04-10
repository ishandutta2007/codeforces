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

int n;
string s;
int cnt[30];
int arr[55];

vector<int> pos[30];
int val[55];
bool used[55];
char ans[55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>s;
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		memset(cnt,0,sizeof(cnt));
		rep(x,0,sz(s)) cnt[s[x]-'a']++;
		rep(x,0,30) pos[x].clear();
		
		memset(val,0,sizeof(val));
		memset(used,false,sizeof(used));
		rep(x,0,26){
			rep(y,0,n) if (!used[y] && val[y]==arr[y]){
				pos[x].push_back(y);
				used[y]=true;
			}
			
			for (auto &it:pos[x]){
				rep(y,0,n) val[y]+=abs(y-it);
			}
		}
		
		int curr=25;
		rep(x,0,30){
			if (sz(pos[x])==0) break;
			while (cnt[curr]<sz(pos[x])) curr--;
			
			for (auto &it:pos[x]){
				ans[it]='a'+curr;
			}
			
			curr--;
		}
		
		rep(x,0,n) cout<<ans[x];
		cout<<endl;
	}
}