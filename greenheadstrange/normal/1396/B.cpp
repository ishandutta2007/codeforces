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
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			s += a;
			mx = max(mx, a); 
		} 
		int fl = 0;
		if (s & 1) fl = 1;
		else {
			if (mx * 2 > s) fl = 1;
			else fl = 0;
		}
		if (fl) cout << "T" << endl;
		else cout << "HL" << endl;
	}
	return 0;
}