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

int n,x;
int a[maxn];
bool solve() {
	scanf("%d%d", &n, &x);
	int s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		s += a[i];
		if (s == x) {
			if (i == n - 1) {
				return false;
			}
			s -= a[i];
			swap(a[i], a[i + 1]);
			s += a[i];
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	puts("");
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		if (!solve()) {
			puts("NO");
		}
	}
}