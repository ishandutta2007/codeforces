#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		if (i == n - 1) {
			++res;
			continue;
		}
		res += n - i;
		res += (n - i - 1) * i;
	}
	cout << res << endl;
	return 0;
}