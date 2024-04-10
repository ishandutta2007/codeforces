// Problem: E. Conveyor
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforces.com/contest/1733/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

int nCk[65][65];
int cnt[250][250];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	nCk[0][0]=1;
	rep(x,1,65){
		nCk[x][0]=1;
		rep(y,1,x+1) nCk[x][y]=nCk[x-1][y-1]+nCk[x-1][y];
	}
	
	// rep(x,0,5){
		// rep(y,0,x+1) cout<<nCk[x][y]<<" "; cout<<endl;
	// }
	
	int TC;
	cin>>TC;
	while (TC--){
		int t,a,b;
		cin>>t>>a>>b;
		
		t-=a+b;
		
		if (t<0){
			cout<<"NO"<<endl;
			continue;
		}
		
		memset(cnt,0,sizeof(cnt));
		int px=0,py=0;
		rep(x,0,a+b){
			if (x<62 && t&(1LL<<(x))){
				rep(y,0,x+1) cnt[x-y][y]+=nCk[x][y];
			}
			
			rep(y,0,x+1){
				int t=cnt[x-y][y];
				cnt[x-y+1][y]+=(t+1)/2;
				cnt[x-y][y+1]+=t/2;
			}
			if (cnt[px][py]%2==0) px++;
			else py++;
		}
		
		//cout<<"hi: "<<px<<" "<<py<<endl;
		
		if (a==py && b==px) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}