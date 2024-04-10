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

string s,t;

vector<ii> memo[10005];
int oa[10005];
int ob[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s>>t;
	memo[0].push_back(ii(0,0));
	
	rep(x,0,sz(s)){
		rep(y,sz(t)+1,0){
			//cout<<x<<" "<<y<<endl;
			//for (auto &it:memo[y]) cout<<it.fi<<"_"<<it.se<<" ";cout<<endl;
		
			if (y!=sz(t) && s[x]==t[y] && !memo[y].empty()){
				ii temp=ii(memo[y].back().first+oa[y]-oa[y+1],0-ob[y+1]);
				
				while (!memo[y+1].empty() && memo[y+1].back().fi+memo[y+1].back().se<=temp.fi+temp.se) memo[y+1].pop_back();
				if (memo[y+1].empty() || memo[y+1].back().fi<temp.fi) memo[y+1].push_back(temp);
			}
			
			if (s[x]=='.'){
				oa[y]++,ob[y]--;
				
				if (!memo[y].empty() && memo[y].back().se+ob[y]<0){
					memo[y].back().fi--;
					memo[y].back().se++;
				}
				if (sz(memo[y])>=2 && memo[y][sz(memo[y])-2].fi==memo[y][sz(memo[y])-1].fi){
					memo[y].pop_back();
				}
			}
			else{
				ob[y]++;
			}
		}
	}
	
	cout<<sz(s)-sz(t)-2*(memo[sz(t)].back().fi+oa[sz(t)])<<endl;
	
}