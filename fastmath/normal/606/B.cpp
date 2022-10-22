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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    string s;
    cin >> s;
    set <ii> ms;
    ms.insert(mp(x, y));
    cout << "1 ";
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == 'L') {
            y = max(1ll, y - 1);
        }
        else if (c == 'R') {
            y = min(m, y + 1);
        }   
        else if (c == 'U') {
            x = max(1ll, x - 1);
        }
        else {
            x = min(n, x + 1);
        }   
        if (i + 1 < s.size()) {
            if (ms.find(mp(x, y)) == ms.end()) {
                cout << "1 ";
            }   
            else {
                cout << "0 ";
            }   
            ms.insert(mp(x, y));
        }
        else {
            cout << n * m - ms.size() << '\n';
        }   
    }   
}