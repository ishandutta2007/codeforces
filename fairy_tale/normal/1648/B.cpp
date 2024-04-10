
#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int f[maxn];

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, c, x, fg = 1;
        cin >> n >> c;
        memset(f, 0, sizeof(int) * (c + 1));
        for (int i = 0; i < n; i++) {
            cin >> x;
            f[x]++;
        }

        for (int i = 1; i <= c; i++) f[i] += f[i - 1];
        for (int i = 2; i <= c; i++) {
            if (f[i] == f[i - 1]) continue;

            for (int j = i; j <= c; j += i) {
                int r = min(j + i - 1, c);
                if (f[r] == f[j - 1]) continue;
                if (f[j / i] == f[j / i - 1]) {
                    fg = 0;
                    break;
                }
            }

            if (!fg) break;
        }

        if (fg) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}