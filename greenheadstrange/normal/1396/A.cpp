//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll a[maxn]; 
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	if (n == 1) {
		cout << 1 << ' ' << 1 << endl << 0 << endl;
		cout << 1 << ' ' << 1 << endl << 0 << endl;
		cout << 1 << ' ' << 1 << endl << -a[1] << endl;
	}
	else {
		cout << 1 << ' ' << n << endl;
		for (int i = 1; i <= n; i++) {
			ll e = (n - 1) - a[i] % (n - 1);
			ll cur = e * n;
			printf("%lld ", cur);
			a[i] += cur;
		}
		cout << endl;
		cout << 1 << ' ' << n - 1 << endl;
		for (int i = 1; i <= n - 1; i++)
			printf("%lld ", -a[i]);
		cout << endl;
		cout << n << ' ' << n << endl;
		cout << -a[n] << endl;
	}
	return 0;
}