//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;


int n, l, r, cnt[maxn];
void solve() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) cnt[i] = 0;
	for (int i = 0; i < l; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 0; i < r; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]--;
	}
	int ans = 0;
	sort(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++) {
		while (cnt[i] <= -2 && l < r) {
			cnt[i] += 2;
			l++;
			r--;
			ans += 1;
		}

		while (cnt[i] >= 2 && l > r) {
			cnt[i] -= 2;
			l--;
			r++;
			ans += 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		while (cnt[i] <= -1 && l < r) {
			cnt[i] += 2;
			l++;
			r--;
			ans += 1;
		}

		while (cnt[i] >= 1 && l > r) {
			cnt[i] -= 2;
			l--;
			r++;
			ans += 1;
		}
	}
	for (int i = 1; i <= n; i++) ans += max(cnt[i], 0);
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		solve();
	}
}