#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll cc = 1;
ll s[maxn];
map<ll, int> tst;
int n, k;
ll ans;
void work(ll a) {
	tst.clear();
	tst[s[0]]++;
	for (int i = 1; i <= n; i++)
		ans += tst[s[i] - a], 
		tst[s[i]]++;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
	}
	for (int i = 0; i < maxn; i++) {
		work(cc);
		cc = cc * k;
		if (cc > 1e15) break;
		if (k == 1) break;
		if (k == -1 && i == 1) break;
	}
	cout << ans << endl;
	return 0;
}
/*
1 2
..
*/