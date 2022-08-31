#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char inp[maxn];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		scanf("%s", inp + 1);
		int l = strlen(inp + 1), tl = l;
		for (int i = 1; i <= x; i++) {
			ll el = tl + 1ll * (inp[i] - '1') * (tl - i);
			int ls = i + 1, rs = l;
			if (l < x)
				for (int j = 0; j < inp[i] - '1'; j++) {
					for (int k = ls; k <= rs; k++)
						if (l >= x) break;
						else inp[++l] = inp[k];
				}
			tl = el % mod;
		}
		if (tl < 0) tl += mod;
		cout << tl << endl;
	}
	return 0;
}