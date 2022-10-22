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
    string s;
    cin >> s;
    int n = s.size();

    bool h = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            h |= s[i] == '(' && s[j] == ')';
        }   
    }       
    if (!h) {
        cout << "0\n";
        exit(0);
    }   

    cout << "1\n";
    for (int l = 0; l <= n; ++l) {
        int op = 0;
        for (int i = 0; i < l; ++i)
            op += s[i] == '(';
        int cl = 0;
        for (int i = l; i < n; ++i)
            cl += s[i] == ')';
        if (op == cl) {
            vector <int> ans;
            for (int i = 0; i < l; ++i)
                if (s[i] == '(')
                    ans.app(i);
            for (int i = l; i < n; ++i)
                if (s[i] == ')')
                    ans.app(i);
            cout << ans.size() << '\n';
            for (int e : ans)   
                cout << e + 1 << ' ';
            cout << '\n';
            exit(0);
        }   
    }   

}