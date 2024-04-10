#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = (1 << 20) + 5;
const int mod = 1e9 + 7;

unordered_map<LL, int> fg;
bool check(int n, int k)
{
    if (n < k) return false;
    LL key = (1LL * n) << 30 | k;
    if (fg.find(key) != fg.end()) return fg[key];

    int w = 0;
    for (int i = k; i <= n; i++) w += ((n ^ i) & i) == 0;
    fg[key] = w & 1;
    return w & 1;
}

int a[maxn];
void solve()
{
    int n, k;
    map<int, int> ans;
    cin >> n>> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        LL val = a[i];
        int j = i + 1;
        while (val < (1 << 20)) {
            // handle
            int x = 0, y = k;
            if(i > 1) {
                x += i - 2;
                y--;
            }
            if(j <= n) {
                x += n - j;
                y--;
            }

            y = max(y, 0);
            if (check(x, y)) ans[val]++;

            if(j > n || a[j] > 20) break;
            val *= 1LL << a[j++];
        }
    }

    vector<int> p;
    for (auto e:ans) {
        if (e.se & 1) p.push_back(e.fi);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    //for (auto e:p) cout<<e<<endl;

    int m = p.size();
    p.push_back(-1);
    for (int i = 0; i < m; i++) {
        putchar('1');
        for (int j = p[i] - 1; j > p[i + 1]; j--) putchar('0');
    }
    if (m == 0) putchar('0');
    putchar('\n');
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Pt = 1;
    //cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}