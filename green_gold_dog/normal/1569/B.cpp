#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<vector<char>> arr(n, vector<char>(n, 'X'));
		vector<ll> num;
		for (ll i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == '1') {
				for (ll j = 0; j < n; j++) {
					if (i != j) {
						arr[i][j] = '=';
						arr[j][i] = '=';
					}
				}
			} else {
				num.push_back(i);
			}
		}
		if (num.size() == 1 || num.size() == 2) {
			cout << "NO" << '\n';
		} else {
			cout << "YES\n";
			ll j = num.size() - 1;
			for (ll i = 0; i < num.size(); i++) {
				arr[num[i]][num[j]] = '+';
				arr[num[j]][num[i]] = '-';
				j = i;
			}
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < n; j++) {
					if (arr[i][j] == 'X') {
						if (i != j) {
							arr[i][j] = '+';
							arr[j][i] = '-';
						}
					}
					cout << arr[i][j];
				}
				cout << '\n';
			}
		}
	}
}

/*
















*/