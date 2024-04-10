#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const ll mod = 124027399712311ll;
int base = 5;
int cnt[maxn];
char inp[maxn];
ll pw[maxn];
ll hs[maxn][2];
ll mul(ll a, ll b) {
	if (b == 0) return 0;
	ll g = mul(a, b / 100);
	g = g * 100;
	g += (b % 100) * a;
	g %= mod;
	return g;
} 
ll gt(int l, int r, int tp) {
	ll cur = hs[r][tp];
	cur -= mul(hs[l - 1][tp], pw[cnt[r] - cnt[l - 1]]);
	cur %= mod;
	if (cur < 0) cur += mod; 
	return cur;
}
int main() {
    srand((unsigned long long)(new char));
    base = rand() % 10000 + 4;
	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * base % mod;
	int n;
	cin >> n;
	scanf("%s", inp + 1);
	int l = strlen(inp + 1);
	for (int i = 1; i <= l; i++) {
		cnt[i] = cnt[i - 1];
		if (inp[i] == '0') cnt[i]++;
		for (int j = 0; j < 2; j++) {
			hs[i][j] = hs[i - 1][j];
			if (inp[i] == '0') {
				hs[i][j] *= base;
				if (i % 2 == j) hs[i][j]++;
				else hs[i][j] += 2;		
				hs[i][j] %= mod;	
			}
		} 
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v, s;
		scanf("%d%d%d", &u, &v, &s);
		if (gt(u, u + s - 1, u & 1) == gt(v, v + s - 1, v & 1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}