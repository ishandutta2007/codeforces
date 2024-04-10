#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define forab(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int digit_sum(int n) {
	int res = 0;
	while(n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;      
	vector<int> ans; 
	forab(i, max(0, n - 81), n) {
		if (i + digit_sum(i) == n) {
			ans.pb(i);
		}
	}
	cout << sz(ans) << "\n";
	for (int x: ans) {
		cout << x << "\n";
	}
	return 0;
}