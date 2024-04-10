#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b, c;
	cin >> n >> a >> b >> c; 
	int res = 0;
	rep(i, 0, n / a + 1) {
		rep(j, 0, n / b + 1) {
			int length = i * a + j * b;
			if (length > n || (n - length) % c) continue;
			res = max(res, i + j + (n - length) / c);
		}
	}
	cout << res;
	return 0;
}