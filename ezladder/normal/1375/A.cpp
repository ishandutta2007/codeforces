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
int a[111];

bool ok() {
	int w1 = 0, w2 = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] - a[i] <= 0) w1++;
		if (a[i + 1] - a[i] >= 0) w2++;
	}
	return w1 >= (n - 1) / 2 && w2 >= (n - 1) / 2;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];

		if (ok()) {
			for (int i = 0; i < n; ++i) cout << a[i] << ' ';
			cout << "\n";
			continue;
		}

		for (int j = 0; j < n; ++j) {
			a[j] = -a[j];
			if (ok()) {
				for (int i = 0; i < n; ++i) cout << a[i] << ' ';
				cout << "\n";
				break;		
			}
		}
	}

}