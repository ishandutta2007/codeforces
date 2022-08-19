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
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n;
int a[maxn];
pi b[maxn];
int mx[maxn];
int nr[maxn];
int r[maxn];
int k[maxn];
pi rr[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n == 0) while(1);
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; ) {
		int j = i;
		while (a[j] == a[i] && j <= n) j++;
		b[cnt++] = mp(j - i, a[i]);
		i = j;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; 1ll * j * i <= n; j++)
			mx[i * j] = i;
	for (int i = 1; i <= n; i++)
		if (!mx[i]) return 0;
	sort(b, b + cnt);
	int apl = 0, bpl = 0;
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (bpl == cnt) {
			while (nr[apl] == b[apl].fi && apl < cnt) apl++;
			bpl = apl;
		}
		nr[bpl]++;	
		if (nr[bpl] <= mx[i]) ans = i;
		bpl++;
	}
	memset(nr, 0, sizeof(nr)), apl = 0, bpl = 0;
	for (int i = 1; i <= ans; i++) {
		if (bpl == cnt) {
			while (nr[apl] == b[apl].fi && apl < cnt) apl++;
			bpl = apl;
		}
		nr[bpl]++, bpl++;
	}
	int p = mx[ans], q = ans / p;
	cout << ans << endl;
	cout << p << ' ' << q << endl;
	for (int i = 0; i < cnt; i++)
		rr[i] = mp(nr[i], b[i].se);
	sort(rr, rr + cnt);
	int num = 0;
	for (int i = cnt - 1; i >= 0; i--)
		for (int j = 0; j < rr[i].fi; j++)
			k[num++] = (rr[i].se);
	int tot = 0;
	for (int i = 0; i < q; i++)
		for (int j = 0; j < p; j++)
			r[j * q + (i + j) % q] = k[tot++];
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++)
			printf("%d ", r[i * q + j]);
		printf("\n");
	}
	return 0;
}