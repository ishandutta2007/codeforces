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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    vector <int> ans;
    int n; cin >> n;
    set <int> ms, in;
    int p = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x > 0) {
            if (ms.find(x) != ms.end()) {
                cout << "-1\n";
                exit(0);
            }   
            ms.insert(x);
            in.insert(x);
        }
        else {
            x = -x;
            if (in.find(x) == in.end()) {
                cout << "-1\n";
                exit(0);
            }   
            in.erase(x);
            if (in.empty()) {
                ms.clear();
                ans.app(i + 1 - p);
                p = i + 1;
            }   
        }   
    }   
    if (ms.size()) {
        cout << "-1\n";
        exit(0);
    }   
    cout << ans.size() << '\n';
    for (int e : ans) cout << e << ' ';
    cout << '\n';
}