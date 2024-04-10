
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

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int f[30];

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        int n = s.size();
        memset(f, 0, sizeof(f));

        for (int i = 0; i < n; i++) {
            int d = s[i] - 'a';
            f[d]++;
        }

        for (int i = 0; i < n; i++) {
            int d = s[i] - 'a';
            f[d]--;
            if (f[d] == 0) {
                cout << s.substr(i) << endl;
                break;
            }
        }
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}