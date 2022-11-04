#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll k;
	cin >> k;
	ll cc = 1;
	for (ll i = 0; i < k; i++) {
		cc *= 2;
	}
	string ss;
	cin >> ss;
	vector<char> s(cc, 0);
	for (ll i = 0; i < cc-1; i++) {
		s[i] = ss[i];
	}
	vector<ll> arr(cc*2, 0);
	for (ll i = arr.size()-1; i >= 1; i--) {
		if (i >= cc) {
			arr[i] = 1;
		} else {
			if (s[cc-i-1] == '?') {
				arr[i] = arr[i*2]+arr[i*2+1];
			}
			if (s[cc-i-1] == '0') {
				arr[i] = arr[i*2+1];
			}
			if (s[cc-i-1] == '1') {
				arr[i] = arr[i*2];
			}
		}
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll num;
		char c;
		cin >> num >> c;
		s[num-1] = c;
		num = cc-num;
		while (num != 0) {
			if (s[cc-num-1] == '?') {
				arr[num] = arr[num*2]+arr[num*2+1];
			}
			if (s[cc-num-1] == '0') {
				arr[num] = arr[num*2+1];
			}
			if (s[cc-num-1] == '1') {
				arr[num] = arr[num*2];
			}
			num = num/2;
		}
		cout << arr[1] << '\n';
	}
}