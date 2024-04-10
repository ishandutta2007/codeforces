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

int get(int n, vector <int> &w, int mod) {
    int r = n % mod;
    int d = n / mod;
    return w.size() * d + (upper_bound(all(w), r) - w.begin());
}

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
        int a, b, q;
        cin >> a >> b >> q;

        vector <int> w;
        for (int i = 0; i < a * b; ++i) {
            if ((i % a) % b != (i % b) % a) {
                w.app(i);
            }   
        }   

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << get(r, w, a * b) - get(l - 1, w, a * b) << ' ';
        }   
        cout << endl;
    }   


}