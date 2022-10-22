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

const int mod = 998244353;
const int maxn = 1e6 + 5;

string s;
int f[maxn];
int col[maxn];
int row[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < n * m; i++) f[i] = s[i] - '0';
    for (int i = 1; i < n * m; i++) f[i] += f[i - 1];

    int colNum = 0;
    for (int i = 0; i < m; i++) col[i] = 0;
    for (int i = 1; i < n * m; i++) row[i] = 0;

    for (int i = 0; i < n * m; i++) {
        int j = i % m;
        int pre = (i >= m ? row[i - m] : 0);
        int sum = f[i] - (i >= m ? f[i - m] : 0);

        row[i] = pre + (sum > 0);
        if (s[i] == '1') {
            if (col[j] == 0) {
                col[j] = 1;
                colNum++;
            }
        }

        cout << row[i] + colNum << " ";
    }
    cout << endl;
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