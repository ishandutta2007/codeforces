#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 400*1000+10;
const ll INF = (ll)1e18;
int n;
int a[nax];
ll mov[21][21];
ll dp[(1<<20)];
ll cost[(1<<20)][21];
vi nxt[21];

int main() {_
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		nxt[a[i]].PB(i);
	}
	for(int x=1; x<=20; x++) {
		for(int y=1; y<=20; y++) {
			if(x==y) continue;
			int wsk = 0;
			for(auto it:nxt[y]) {
				while(wsk<(int)nxt[x].size()&&nxt[x][wsk]<it) {
					wsk++;
				}
				mov[x][y]+=wsk;
			}
		}
	}
	for(int i=1; i<(1<<20); i++) {
		int f = -1, s = -1;
		for(int j=0; j<20; j++) {
			if((1<<j)&i) {
				s = j;
				if(f==-1) f = j;
			}
		}
		for(int j=0; j<20; j++) {
			if((1<<j)&i) {
				if(j==f) cost[i][f] = cost[i^(1<<s)][f]+mov[s+1][f+1];
				else cost[i][j] = cost[i^(1<<f)][j]+mov[f+1][j+1];
			}
		}
	}
	for(int i=1; i<(1<<20); i++) {
		dp[i] = INF;
		for(int j=0; j<20;j++) {
			if((1<<j)&i) {
				dp[i] = min(dp[i],(ll)(dp[i^(1<<j)]+cost[i][j]));
			}
		}
	}
	cout<<dp[(1<<20)-1];
}