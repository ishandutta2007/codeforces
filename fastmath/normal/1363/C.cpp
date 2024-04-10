#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector <int> pw(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            ++pw[u]; ++pw[v];
        }   
        if (pw[x] <= 1) {
            cout << "Ayush" << endl;
        }   
        else {
            if (n % 2 == 0)
                cout << "Ayush" << endl;
            else
                cout << "Ashish" << endl;
        }   
    }   
}