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
const int mod = 1e9 + 7;

int l[maxn], r[maxn];

bool check(int L, int R, int x) {
    x = -x;
    return (L <= x && x <= R);
}

void solve()
{
    string s;
    int n, x;
    cin >> s;
    n = s.length();
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }

    l[0] = r[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            r[i + 1] = r[i] + 1;
            l[i + 1] = l[i] - 1;
        } else {
            x = (s[i] == '(') ? 1 : -1;
            l[i + 1] = l[i] + x;
            r[i + 1] = r[i] + x;
        }

        if (l[i + 1] < 0) l[i + 1] += 2;
        //cout << l[i + 1] << " " << r[i + 1] << endl;
        if (l[i + 1] > r[i + 1] || r[i + 1] < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = n - 1, u = 0; i >= 0; i--) {
        if (s[i] == '?') {
            if (check(l[i], r[i], u - 1) && check(l[i], r[i], u + 1)) {
                cout << "NO" << endl;
                return;
            } else {
                if (check(l[i], r[i], u - 1)) u -= 1;
                else u += 1;
            }
        } else {
            x = (s[i] == '(') ? 1 : -1;
            u += x;
        }
    }

    cout << "YES" << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("input.txt", "r", stdin);
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