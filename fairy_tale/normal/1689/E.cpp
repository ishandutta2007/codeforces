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

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int a[2005], p[2005], tot;
vector<int> f[33];

int ff(int x) {
    if (p[x] != x) p[x] = ff(p[x]);
    return p[x];
}

void merge(int x, int y) {
    x = ff(x);
    y = ff(y);
    if (x != y) {
        tot++;
        p[x] = y;
    }
}

bool check(int n) {
    vector<int> fa(30, -1);
    for (int i = 0; i < n; i++) p[i] = i;
    tot = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if ((a[i] >> j) & 1) {
                if (fa[j] == -1) fa[j] = i;
                else merge(i, fa[j]);
            }
        }
    }

    return (tot == n - 1);
}

void printAns(int val, int n) {
    cout << val << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void solve()
{
    int n, d = 0, base = 0;
    cin >> n;

    for (int i = 0; i <= 30; i++) f[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            a[i] = 1;
            base++;
        }

        int k = __builtin_ctz(a[i]);
        f[k].push_back(i);
        d = max(d, k);
    }

    if (check(n)) {
        printAns(base, n);
        return;
    }

    for (auto e:f[d]) {
        a[e]--;
        if (check(n)) {
            printAns(base + 1, n);
            return;
        }
        a[e]++;
    }

    a[f[d][0]]++;
    if (check(n)) {
        printAns(base + 1, n);
        return;
    }
    a[f[d][0]]--;

    a[f[d][0]]--;
    a[f[d][1]]++;
    printAns(base + 2, n);
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