#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int mod = 998244353;
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % mod; }
int pwr(int a, int b = mod - 2)
{
    if (!b) return 1;
    int h = pwr(a, b >> 1);
    h = mul(h, h);
    if (b & 1) h = mul(h, a);
    return h;
}

const int maxn = 1 << 18;
int f[maxn], invf[maxn];
int c(int n, int k)
{
    return mul(f[n], mul(invf[k], invf[n - k]));
}
int sum[maxn * 2], prod[maxn * 2];
void update(int i, int x)
{
    sum[i += maxn] += x;
    prod[i] = invf[sum[i]];
    for (i = (i >> 1); i > 0; i >>= 1)
    {
        sum[i] = add(sum[i * 2], sum[i * 2 + 1]);
        prod[i] = mul(prod[i * 2], prod[i * 2 + 1]);
    }
}
pair<int, int> query(int l, int r)
{
    int s = 0, p = 1;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
        {
            s += sum[l];
            p = mul(p, prod[l]);
            l++;
        }
        if (r & 1)
        {
            r--;
            s += sum[r];
            p = mul(p, prod[r]);
        }
    }
    return { s, mul(f[s], p) };
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    fill(prod, prod + maxn * 2, 1);
    f[0] = 1;
    for (int i = 1; i < maxn; i++) f[i] = mul(f[i - 1], i);
    for (int i = 0; i < maxn; i++) invf[i] = pwr(f[i]);
    int n, m;
    cin >> n >> m;
    for (int i = 0, si; i < n; i++)
    {
        cin >> si;
        update(si, 1);
    }
    int ans = 0;
    for (int i = 0, ti; i < m; i++) // we'll try the first letter where they differ
    {
        cin >> ti;
        pair<int, int> small = query(0, ti - 1), big = query(ti, maxn - 1);
        if (small.first)
        {
            int cnt = c(small.first + big.first - 1, big.first);
            upd(ans, mul(cnt, mul(small.second, big.second)));
        }
        if (sum[maxn + ti] == 0)
        {
            if (i == n) upd(ans, 1);
            break;
        }
        update(ti, -1);
    }
    cout << ans << "\n";
	return 0;
}