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
int a[300007];
int b[300007];
int was[300007];
int kek[300007];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i <= n; ++i) was[i] = 0;
		for (int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i], was[a[i]]++;

		sort(b, b + n);
		int ok = 1;
		for (int i = 0; i < n; ++i) if (b[i] != i + 1) ok = 0;
		cout << ok;

		for (int i = 2; i <= n; ++i) {
			kek[i] = 0;			
		}

		int uk1 = 0, uk2 = n - 1;
		int now = 1;
		for (int len = n; len >= 2; --len) {
			if (was[now] == 0) break;
			kek[len] = 1;
			if (was[now] > 1) break;
			if (a[uk1] == now) {
				uk1++;
			} else if (a[uk2] == now) {
				--uk2;
			} else {
				break;
			}
			++now;
		}


		for (int i = 2; i <= n; ++i) {
			cout << kek[i];
		}

		cout << "\n";
	}

}