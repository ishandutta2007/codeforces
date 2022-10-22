#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

// #define DEBUG

int cnt[120];

void Main(){
	int t; cin >> t;
	while (t--){
		memset(cnt, 0, sizeof(cnt));
		int n; cin >> n;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			cnt[abs(x)] += 1;
		}
		int ans = 0;
		for (int i = 0; i <= 100; i++){
			if (i == 0){
				if (cnt[i] >= 1){ ans += 1; }
			}
			else{
				if (cnt[i] == 1){ ans += 1; }
				if (cnt[i] >= 2){ ans += 2; }
			}
		}
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}