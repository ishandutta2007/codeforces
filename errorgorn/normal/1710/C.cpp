//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
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

const int MOD=998244353;
const int mask[]={0,1,2,4,4,2,1,0};

string s;
int memo[2][8][8];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>s;
	
	int a=0,b=1;
	memo[a][7][0]=1;
	
	rep(i,0,sz(s)){
		memset(memo[b],0,sizeof(memo[b]));
		
		rep(mask1,0,8) rep(mask2,0,8){
			bool ok=true;
			int nask1=mask1;
			rep(bit,0,3){
				if (mask1&(1<<bit)){
					if (s[i]=='0'){
						if (mask2&(1<<bit)) ok=false;
					}
					else{
						if ((mask2&(1<<bit))==0) nask1^=1<<bit;
					}
				}
			}
			
			if (ok){
				rep(mask3,0,8){
					memo[b][nask1][mask3|mask[mask2]]=
						(memo[b][nask1][mask3|mask[mask2]]+memo[a][mask1][mask3])%MOD;
				}
			}
		}
		
		swap(a,b);
	}
	
	int ans=0;
	rep(x,0,8) ans=(ans+memo[a][x][7])%MOD;
	cout<<ans<<endl;
}