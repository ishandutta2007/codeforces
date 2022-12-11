#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int k;

bool check(string& s) {
	int sum = 0;
	for (int i = 0; i < k; ++i) sum += s[i] == '1';
	if (sum * 2 != k) return 0;
	for (int i = k; i < s.size(); ++i) {
		if (s[i] == '1') sum++;
		if (s[i - k] == '1') sum--;
	if (sum * 2 != k) return 0;

	}
	return 1;
}


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s >> k >> s;

		int ok = 1;
		for (int i = 0; i < k; ++i) {
			int w1 = 0, w2 = 0;
			for (int j = i; j < s.size(); j += k) {
				if (s[j] == '1') w1 = 1;
				if (s[j] == '0') w2 = 1;
			}
			if (w1 == 1 && w2 == 1) {
				ok = 0;
				break;
			}
			for (int j = i; j < s.size(); j += k) {
				if (w1) s[j] = '1';
				if (w2) s[j] = '0';
			}
		}
		if (ok == 0) {
			cout << "NO\n";
			continue;
		}

		int sum = 0;
		for (int i = 0; i < k; ++i) sum += s[i] == '1';

	//		cout << s << endl;
		
		for (int i = 0; i < k; ++i) {
			if (sum * 2 < k && s[i] == '?') {
				for (int j = i; j < s.size(); j += k) {
					s[j] = '1';
				}
				++sum;
			}
		}

		for (int i = 0; i < s.size(); ++i) if (s[i] == '?') s[i] = '0';

		if (check(s)) cout << "YES\n"; else cout << "NO\n";
	}

}