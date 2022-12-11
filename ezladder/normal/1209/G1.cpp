#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, q;
int a[200007];
int last[200007];
int a_last[200007];

int solve(int l, int r){
	map<int, int> ma;
	for (int i = l; i <= r; i++) ma[a[i]]++;
	int ww = 0;
	for (auto c : ma) ww = max(ww, c.y);
	return (r - l + 1) - ww;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = n - 1; i >= 0; i--){
		if (a_last[a[i]] == 0){
			a_last[a[i]] = i;
		}
		last[i] = a_last[a[i]];
	}

	int ans = 0;

	int v = 0;
	while(1){
		if (v == n) break;
		int save = v;
		int ma = last[v];
		while(1){
			if (ma == v) break;
			else {
				v++;
				ma = max(ma, last[v]);
			}
		}
		ans += solve(save, v);
		v++;
	}

	cout << ans;
}