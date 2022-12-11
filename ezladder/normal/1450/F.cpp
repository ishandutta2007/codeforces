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
int a[100007];
int kk[100007];

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i <= n; ++i) kk[i] = 0;
		for (int i = 0; i < n; ++i) cin >> a[i];

		if (n == 1) {
			cout << "0\n";
			continue;
		}

		int cnt = 1;
		for (int i = 0; i + 1 < n; ++i) {
			if (a[i] == a[i + 1]) {
				++cnt;
				kk[a[i]] += 2;
			}
		}
		kk[a[0]]++;
		kk[a[n - 1]]++;

		int v = 1;
		for (int i = 1; i <= n; ++i) if (kk[v] < kk[i]) v = i;
		
		if (cnt == 1) {
			cout << "0\n";
		} else {

			if (kk[v] <= cnt + 1) {
				cout << cnt - 1 << "\n";
			} else {
				for (int i = 0; i + 1 < n; ++i) {
					if (kk[v] <= cnt + 1) break;
					if (a[i] != a[i + 1]) {
						if (a[i] != v && a[i + 1] != v) {
							kk[a[i]]++;
							kk[a[i + 1]]++;
							++cnt;
						}
					}
				}
				if (kk[v] <= cnt + 1) {
					cout << cnt - 1 << "\n";
				} else {
 					cout << "-1\n";
				}
			}
		}
	}

}