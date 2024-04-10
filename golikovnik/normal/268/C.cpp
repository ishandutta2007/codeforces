#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0) {
		puts("0");
		return 0;
	}
	int x = 0;
	int y = m;
	cout << min(n+1, m+1) << endl;
	for (int i = 0; i < min(n + 1, m + 1); ++i) {
		cout << x << " " << y << endl;
		++x;
		--y;
	}
	return 0;
}