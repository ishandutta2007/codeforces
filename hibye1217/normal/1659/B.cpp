#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

int cnt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; string s; cin >> n >> k >> s;
		if (k & 1){
			for (char& ch : s){ ch ^= '0'^'1'; }
		}
		for (int i = 0; i < n; i++){
			if (k > 0){
				if (s[i] == '0'){ k -= 1; s[i] = '1'; cnt[i] += 1; }
			}
		}
		cnt[n-1] += k; if (k & 1){ s[n-1] = '0'; }
		cout << s << endl;
		for (int i = 0; i < n; i++){ cout << cnt[i] << ' '; }
		cout << endl;
		for (int i = 0; i < n; i++){ cnt[i] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}