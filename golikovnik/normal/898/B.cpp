#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i * a <= n; ++i) {
		int left = n - i * a;
		if (left % b == 0) {
			cout << "YES" << endl;
			cout << i << " " << left / b << endl;
			return 0;
		}
	}       
	cout << "NO" << endl;
	return 0;
}