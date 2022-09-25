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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int res[]={1869,8196,1986,1698,6198,1689,1968};

string s;
int cnt[10];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for (auto &it:s) cnt[it-'0']++;
	
	cnt[1]--;
	cnt[6]--;
	cnt[8]--;
	cnt[9]--;
	
	int val=0;
	int p=10000%7;
	
	string ans;
	rep(x,0,sz(s)-4-cnt[0]){
		rep(y,1,10) if (cnt[y]){
			val=(val+p*y)%7;
			p=p*10%7;
			cnt[y]--;
			ans+=(char)('0'+y);
		}
	}
	
	reverse(all(ans));
	cout<<ans<<res[val];
	rep(x,0,cnt[0]) cout<<0;
}