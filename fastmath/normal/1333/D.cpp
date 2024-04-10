#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 3007;
vector <int> ans[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int mn = -1;
    for (int t = 0; ; ++t) {
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                ans[t].app(i);
                swap(s[i], s[i + 1]);
                ++i;
            }   
        }   
        if (ans[t].empty()) {
            mn = t;
            break;
        }   
    }   

    int mx = 0;
    for (int t = 0; t < mn; ++t)
        mx += ans[t].size();
    
    if (k < mn || mx < k) {
        cout << -1 << endl;
    }   
    else {
        int want = k - mn;
        for (int i = 0; i < mn; ++i) {
            int add = min(want, (int)ans[i].size() - 1);
            want -= add;

            int op = (int)ans[i].size() - add;
            cout << op << ' ';
            for (int j = 0; j < op; ++j)
                cout << ans[i][j] + 1 << ' ';
            cout << endl;

            for (int j = op; j < ans[i].size(); ++j) {
                cout << 1 << ' ' << ans[i][j] + 1 << endl;
            }                         
        }   
    }   
}