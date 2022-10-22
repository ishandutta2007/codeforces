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

string s;
int v[maxn];
int a, b, c, d, w;

void solve()
{
    int n;
    vector<int> f[4];
    cin >> a >> b >> c >> d;
    cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++) v[i] = s[i] - 'A';

    int st = v[0], len = 1;
    a += c + d;
    b += c + d;
    for (int i = 0; i < n; i++) {
        if (v[i]) b--;
        else a--;
    }
    if (a != 0 || b != 0) {
        cout << "NO" << endl;
        return;
    }

    w = 0;
    auto work = [](int st, int len) {
        int x = len / 2;
        if (!(len & 1)) {
            if (st) {
                if (x <= d) d -= x;
                else {
                    x -= d;
                    d = 0;
                    c -= x - 1;
                }
            } else {
                if (x <= c) c -= x;
                else {
                    x -= c;
                    c = 0;
                    d -= x - 1;
                }
            }

        } else w += x;
        return;
    };

    for (int i = 1; i < n; i++) {
        if (v[i] == (st ^ (len & 1))) len++;
        else {
            if (len > 1) f[st << 1 | (len & 1)].push_back(len);
            st = v[i];
            len = 1;
        }
    }
    if (len > 1) f[st << 1 | (len & 1)].push_back(len);

    sort(f[0].begin(), f[0].end());
    for (auto e:f[0]) work(0, e);
    sort(f[2].begin(), f[2].end());
    for (auto e:f[2]) work(1, e);

    for (auto e:f[1]) work(0, e);
    for (auto e:f[3]) work(1, e);

    if (w >= c + d) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
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