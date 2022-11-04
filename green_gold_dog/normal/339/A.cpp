#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	vector<char> arr;
	for (ll i = 0; i < s.size(); i += 2) {
	  arr.push_back(s[i]);
	}
	sort(arr.begin(), arr.end());
	for (ll i = 0; i < arr.size(); i++) {
	  if (i != 0) {
	    cout << '+';
	  }
	  cout << arr[i];
	}
}

/*
















*/