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

int n;
char s[maxn],a[maxn],b[maxn];
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}


void solve() {
	scanf("%d", &n);
	scanf("%s", s);
	int cnt1 = 0;
	for (int i = 0; i < n; i++) cnt1 += s[i] == '1';
	if (cnt1 % 2 != 0) {
		puts("NO");
		return;
	}
	if (s[0] != '1' || s[n - 1] != '1') {
		puts("NO");
		return;
	}
	cnt1 /= 2;
	int f1 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (cnt1 > 0) {
				a[i] = b[i] = '(';
			} else {
				a[i] = b[i] = ')';
			}
			cnt1--;
		} else {
			if (f1) a[i] = '(', b[i] = ')';
			else a[i] = ')', b[i] = '(';
			f1 ^= 1;
		}
	}
	a[n] = b[n] = 0;
	puts("YES");
	puts(a);
	puts(b);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
		solve();

}