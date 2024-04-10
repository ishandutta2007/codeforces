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

int cnt[30];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		for (char c : s){ cnt[c-'a'] += 1; }
		int pc = 0, lc = 0;
		for (int i = 0; i < 26; i++){
			pc += cnt[i] / 2;
			lc += cnt[i] % 2;
		}
		int ans = pc/k * 2;
		pc -= pc/k*k; lc += 2*pc; pc = 0;
		if (lc >= k){ ans += 1; }
		else{ ans += 0; }
		cout << ans << endl;
		memset(cnt, 0, sizeof(cnt));
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