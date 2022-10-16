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
	if (n == 1) {
		cout << "3" << endl;
	} else if (n == 2) {
		cout << "4" << endl;
	} else {
		cout << n-2 << endl;
	}
	return 0;
}