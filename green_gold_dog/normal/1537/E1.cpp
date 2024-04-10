#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ms = "";
	for (ll i = 0; i < k; i++) {
		ms += "z";
	}
	while (s.size() > 0) {
		string now = "";
		while (now.size() < k) {
			now += s;
		}
		while (now.size() != k) {
			now.pop_back();
		}
		ms = min(ms, now);
		s.pop_back();
	}
	cout << ms;
}