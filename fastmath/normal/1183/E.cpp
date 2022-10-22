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

struct Comp {
    bool operator () (const string a, const string b) const {
        return a.size() > b.size() || (a.size() == b.size() && a < b);
    }   
};  

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k;
    string s;
    cin >> n >> k >> s;

    set <string, Comp> ms;
    set <string> used;
    ms.insert(s);
    used.insert(s);
    
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        if (ms.empty()) {
            cout << "-1\n";
            exit(0);
        }   
        string t = *ms.begin();
        ms.erase(ms.begin());
        ans += s.size() - t.size();
        for (int j = 0; j < t.size(); ++j) {
            string add = t.substr(0, j) + t.substr(j + 1, t.size() - j - 1);
            if (used.find(add) == used.end())
                ms.insert(add);
        }   
    }   

    cout << ans << '\n';
}