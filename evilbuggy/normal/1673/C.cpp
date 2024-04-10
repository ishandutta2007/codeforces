#include <bits/stdc++.h>
using namespace std;

const int maxn = 40005;
const int mod = 1000*1000*1000 + 7;

int dp[maxn];
vector<int> pals;

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline bool isPal(int n){
	vector<int> a, b;
	while(n){
		a.emplace_back(n%10);
		b.emplace_back(n%10);
		n /= 10;
	}
	reverse(b.begin(), b.end());
	return a == b;
}

void init(){
	memset(dp, 0, sizeof(dp));
	for(int n = 1; n < maxn; n++){
		if(isPal(n)){
			pals.emplace_back(n);
		}
	}
	dp[0] = 1;
	for(int x : pals){
		for(int i = 0; i + x < maxn; i++){
			add(dp[i + x], dp[i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}