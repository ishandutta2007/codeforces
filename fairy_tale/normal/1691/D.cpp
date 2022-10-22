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
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int a[maxn], st[maxn];
LL s[maxn], pre[maxn], f[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    int tail = 0;
    for (int i = 1; i <= n; i++) {
        LL val = s[i - 1];
        while (tail && a[i] >= a[st[tail]]) {
            val = min(val, f[tail]);
            tail--;
        }

        st[++tail] = i;
        f[tail] = val;
        pre[tail] = val + a[i];
        if (tail > 1) pre[tail] = min(pre[tail], pre[tail - 1]);
        if (s[i] > pre[tail]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}


int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}