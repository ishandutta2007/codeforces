#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		string s;
		cin >> s;
		s.push_back('-');
		char pred = '-';
		for (ll i = 0; i < n; i++) {
			if (s[i] == '?') {
				ll cb = pred == 'B', cr = pred == 'R';
				ll now = i;
				while (s[now] == '?') {
					now++;
				}
				cb += s[now] == 'B';
				cr += s[now] == 'R';
				if (cb == cr) {
					if (pred == 'B') {
						s[i] = 'R';
						i++;
						for (; i < now; i++) {
							if (s[i - 1] == 'B') {
								s[i] = 'R';
							} else {
								s[i] = 'B';
							}
						}
					} else {
						s[i] = 'B';
						i++;
						for (; i < now; i++) {
							if (s[i - 1] == 'B') {
								s[i] = 'R';
							} else {
								s[i] = 'B';
							}
						}
					}
				}
				if (cb > cr) {
					if (pred == '-') {
						s[i] = ((now - i) % 2 == 1 ? 'R' : 'B');
						i++;
					} else {
						s[i] = 'R';
						i++;
					}
					for (; i < now; i++) {
						if (s[i - 1] == 'B') {
							s[i] = 'R';
						} else {
							s[i] = 'B';
						}
					}
				}
				if (cb < cr) {
					if (pred == '-') {
						s[i] = ((now - i) % 2 == 1 ? 'B' : 'R');
						i++;
					} else {
						s[i] = 'B';
						i++;
					}
					for (; i < now; i++) {
						if (s[i - 1] == 'B') {
							s[i] = 'R';
						} else {
							s[i] = 'B';
						}
					}
				}
			}
			pred = s[i];
		}
		s.pop_back();
		cout << s << '\n';
	}
}

/*
















*/