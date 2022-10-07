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

int n,k;
string s[1005];
char grid[2005][2005];

string ans[1005];
vector<int> pos[2005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		k=n-k+1;
		
		rep(x,0,n) cin>>s[x];
		rep(x,0,n) ans[x]=string(n,'1');
		
		rep(x,0,2*n) rep(y,0,2*n) grid[x][y]='0';
		rep(x,0,n) rep(y,0,n) grid[x-y+n][x+y]=s[x][y];
		rep(x,0,2*k) pos[x].clear();
		
		rep(x,0,k){
			for (int y=-x;;y=(y<0?-y:-(y-1))){
				int mn=0;
				if (y!=-x) mn=max(mn,pos[k+y-1].back());
				if (y!=x) mn=max(mn,pos[k+y+1].back());
				
				bool ok=false;
				rep(z,mn,2*n) if (grid[n+y][z]=='1'){
					pos[k+y].pub(z);
					ans[(z+(n+y-n))/2][(z-(n+y-n))/2]='0';
					ok=true;
					break;
				}
				
				if (!ok){
					cout<<"NO"<<endl;
					goto die;
				}
				
				if (y==0) break;
			}
		}
		
		cout<<"YES"<<endl;
		rep(x,0,n) cout<<ans[x]<<endl;
		
		die:;
	}
}