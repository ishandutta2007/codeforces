//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
#define maxn 200005
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
int x[maxn];
int to, ca;
bool chk(int t) {
	for (int i = t; i >= 1; i--) {
		if (t + 1 - i + x[i] > to) return 0; 
	}
	return 1; 
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		for (int i = 1; i <= m; i++)
			scanf("%d", &x[i]);
		sort(x + 1, x + m + 1); 
		if (a < b) {
			to = b - 1, ca = b - a - 1;
		}
		else to = n - b, ca = a - b - 1;
		ca = min(ca, m); 
		int l = 0, r = ca;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (chk(mid + 1)) l = mid + 1;
			else r = mid;
		} 
		cout << l << endl;
	}
	return 0;
}