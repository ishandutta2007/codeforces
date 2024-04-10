#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
ll a[100007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];

	if (n == 1) {
		cout << "1 1\n" << -a[0] << endl;
		cout << "1 1\n" << 0 << endl;
		cout << "1 1\n" << 0 << endl;
		exit(0);
	}

	cout << 1 << ' ' << n << endl;
	for (int i = 0; i < n; ++i) {
		ll ost = a[i] % (n - 1);
		if (ost < 0) ost += n - 1;
		ll need = n - 1 - ost;
		a[i] += need * (ll)n;
		cout << need * (ll)n << ' ';
	}
	cout << endl;
	cout << "1 1\n" << -a[0] << endl;
	cout << 2 << ' ' << n << endl;
	for (int i = 1; i < n; ++i) {
		cout << -a[i] << ' ';
	}
}