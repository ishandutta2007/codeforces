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
const int INF = 1ll << 32;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int l;
    cin >> l;
    vector <int> s;
    multiset <int> ms;
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        string t;
        cin >> t;
        if (t == "for") {
            int n;
            cin >> n;
            s.app(n);
            if (n > 1) ms.insert(n);
        }   
        else if (t == "end") {
            if (s.back() > 1) ms.erase(ms.find(s.back()));
            s.pop_back();
        }   
        else {
            int f = 1;
            for (int e : ms) {
                f *= e;
                if (f >= INF) {
                    cout << "OVERFLOW!!!\n";
                    exit(0);
                }                                      
            }   
            ans += f;
            if (ans >= INF) {
                    cout << "OVERFLOW!!!\n";
                    exit(0);
            }   
        }   
    }   
    cout << ans << '\n';
}