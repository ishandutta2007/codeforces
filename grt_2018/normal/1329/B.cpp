#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 65;
int t,d,m;

ll cnt(int b) {
	if(b==0) {
		return 1;
	}
	if((1<<b)>d) return 0;
	if((1<<(b+1)>d)) {
		return d - (1<<b) +1;
	}
	return (1<<(b));
}

int dp[nax][nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> d >> m;
		dp[0][0] = 1;
		int ans = 0;
		for(int l = 1; l <= 30; l++) {
			//cout<<cnt(l-1)<<" ";
			for(int b = 1; b <=30; b++) {
				ll x = cnt(b-1)%m;
				int sum = 0;
				for(int b2 = 0; b2 < b; b2++) {
					sum = (sum + dp[l-1][b2])%m;
				}
				dp[l][b] = ((ll)x*sum)%m;
				ans = (ans+dp[l][b])%m;
				//cout << l << " "<< b <<" "<<x <<" "<<dp[l][b]<<"\n";
			}
		}
		cout<< ans <<"\n";
	}
	
}