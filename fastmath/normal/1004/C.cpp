#include <bits/stdc++.h>
    
using namespace std;

#define int long long
#define x first
#define y second   

const int MAXN = 1e5 + 7;

int l[MAXN], r[MAXN];
int kek[MAXN];
int pref[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
	 	cin >> a[i];
	}

	for (int i = 0; i < MAXN; ++i) {
	 	l[i] = MAXN;
	 	r[i] = -1;
	}

	for (int i = 0; i < n; ++i) {
	 	r[a[i]] = max(r[a[i]], i);
	 	l[a[i]] = min(l[a[i]], i);
	}

	for (int i = 0; i < MAXN; ++i) {
	 	kek[l[i]]++;
	}
	
	for (int i = 0; i < MAXN - 1; ++i) {
		pref[i + 1] = pref[i] + kek[i];
	}

	int ans = 0;
	for (int i = 0; i < MAXN; ++i) {
		if (r[i] != -1) {
		 	ans += pref[r[i]];
		}
	}

	cout << ans << '\n';
    return 0;
}