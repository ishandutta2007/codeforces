#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(){
	LL k;
	cin >> k;
	vector<LL> a(7);
	LL tot = 0;
	for(int i = 0; i < 7; i++){
		cin >> a[i];
		tot += a[i];
	}
	LL best = k * 8 + 1;
	for(int b = 0; b < 7; b++){
		for(int len = 0; len < 7; len++){
			LL ans = 0;
			for(int r = 0; r < len; r++){
				ans += a[(b + r) % 7];
			}
			LL days = len;
			if(k > ans){
				LL f = k - ans;
				days += ((f + tot - 1)/ tot) * 7;
			}
			best = min(best, days);
		}
	}
	cout << best << '\n';
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}