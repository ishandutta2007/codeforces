#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
bool bpr[maxn];
int prs[maxn], prcnt  = 0;
ll wk(ll a, ll b) {
	if (a == 1) return a;
	if (b == 0) return a;
	ll cur = a, uu = a;
	for (int i = 0; i < prcnt; i++)
		if (a % prs[i] == 0) {
			cur /= prs[i], cur *= (prs[i] - 1);
			while (uu % prs[i] == 0)	
				uu /= prs[i];
		}
	if (uu != 1) cur /= uu, cur *= (uu - 1);
	return wk(cur, b - 1);
}
int main() {
	for (int i = 0; i < maxn; i++)
		bpr[i] = 1;
	for (int i = 2; i < maxn; i++) {
		if (bpr[i]) {
			prs[prcnt++] = i;
			for (int j = 2; j * i < maxn; j++)
				bpr[i * j] = 0;
		}
	}
	ll n, k;
	cin >> n >> k;
	cout << wk(n, (k + 1) / 2) % mod;
	return 0;
}
/*
CHHOCH
*/