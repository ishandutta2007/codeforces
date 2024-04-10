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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    string mem = "RPS";
    while (t--) {
        vector <int> a(3), b(3);
        int n;
        cin >> n;
        cin >> a[0] >> a[1] >> a[2];

        vector <char> ans(n, 0);

        string s;
        cin >> s;
        int win = 0;
        int i = 0;
        for (char c : s) {
            if (c == 'R') {
                if (a[1]) {
                    --a[1];
                    ans[i] = mem[1];
                    ++win;
                }
            }
            else if (c == 'P') {
                if (a[2]) {
                    --a[2];
                    ans[i] = mem[2];
                    ++win;
                }
            }
            else {
                if (a[0]) {
                    --a[0];
                    ans[i] = mem[0];
                    ++win;
                }
            }
            ++i;
        }
        for (int i = 0; i < n; ++i) {
            if (!ans[i]) {
                for (int j = 0; j < 3; ++j) {
                    if (a[j]) {
                        ans[i] = mem[j];
                        --a[j];
                        break;
                    }   
                }   
            }   
        }   
        if (win >= (n + 1) / 2) {
            cout << "YES\n";
            for (char e :ans)
                cout << e;
            cout << '\n';
        }        
        else {
            cout << "NO\n";
        }   
    }
}