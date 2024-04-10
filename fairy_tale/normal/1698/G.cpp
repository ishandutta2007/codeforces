#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int len;
__uint128_t m;
map<__uint128_t, int> q;

__uint128_t mul(__uint128_t x, __uint128_t y) {
    __uint128_t res = 0;
	for(int i = 0; i < len; i++) { // res = x * y
        if((y >> i) & 1) res ^= x << i;
	}
	for(int i = len + len - 2; i >= len; i--) { // res %= m  
        if((res >> i) & 1) res ^= m << (i - len);
	}
	return res;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length(), pre = 0;
    while (pre < n && s[pre] == '0') pre++;
    if (pre == n) {
        cout << -1 << endl;
        return;
    }

    m = 0;
    for (int i = pre; i < n; i++) m |= (1LL * (s[i] - '0')) << (i - pre);
    pre++;
    if (m == 1) {
        cout << pre << " " << pre + 1 << endl;
        return;
    }

    len = 0;
    while ((m >> (len + 1))) len++;

    __uint128_t x = 1;
    for (int i = 0; i < (1 << 18); i++) {
        q[x] = i;
        x = mul(x, 2);
    }
    __uint128_t y = x;
    for (LL i = 1; i < (1 << 18); i++) {
        if (q.count(y)) {
            cout << pre << " " << pre + (i << 18) - q[y] << endl;
            return;
        }
        y = mul(y, x);
    }
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}