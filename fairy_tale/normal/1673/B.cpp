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

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int pre[26];
    int n = s.length();
    int mask = 0;
    for (auto e:s) mask |= 1 << (e - 'a');
    memset(pre, -1, sizeof(pre));
    for (int i= 0; i < n; i++) {
        int d = pre[s[i] - 'a'];
        if (d >= 0) {
            for (int j = 0; j < 26; j++){
                if ((mask >>j) & 1) {
                    if (pre[j] < d) {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
        }
        pre[s[i]-'a'] = i;
    }
    cout<<"YES"<<endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Pt = 1;
    cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}