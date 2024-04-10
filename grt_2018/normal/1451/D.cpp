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

//~ const int nax = 100 + 10;
int t, d, k;
//~ bool dp[nax][nax];

int main() {_
	cin >> t;
	//~ for(int r = 1; r <= 100; ++r) {
		//~ for(int i = 0; i <= r; ++i) {
			//~ for(int j = 0; j <= r; ++j) dp[i][j] = 0;
		//~ }
		//~ for(int i = r; i >= 0; --i) {
			//~ for(int j = r; j >= 0; --j) {
				//~ if(1LL * i * i + 1LL *j * j > 1LL * r * r) {
					//~ dp[i][j] = 0;
				//~ } else {
					//~ if(!dp[i + 1][j] && 1LL * (i+1) * (i+1) + 1LL *j * j <= 1LL * r * r) {
						//~ dp[i][j] = 1;
					//~ }
					//~ if(!dp[i][j+1] && 1LL * (i) * (i) + 1LL *(j+1) * (j+1) <= 1LL * r * r) {
						//~ dp[i][j] = 1;
					//~ }
				//~ }
			//~ }
		//~ }
		//~ ll x = 0;
		//~ while(2 * (x + 1) * (x + 1) <= 1LL * r * r) x++;
		//~ cout << r << " " << dp[0][0] << " ";
		//~ if(x * x + (x + 1) * (x + 1) <= 1LL * r * r) {
			//~ cout << "1\n";
		//~ } else {
			//~ cout << "0\n";
		//~ }
	//~ }
	while(t--) {
		cin >> d >> k;
		ll l = 0, r = d, mid;
		while(l <= r) {
			mid = (l + r)/2;
			if(sqrtl(2LL) * mid * k <= 1LL * d) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		l--;
		//~ cout << l << "\n";
		if(l * l * k * k + (l + 1) * (l + 1) * k * k <= 1LL * d* d) {
			cout << "Ashish\n";
		} else {
			cout << "Utkarsh\n";
		}
	}
		
	
}