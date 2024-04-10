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
        int n, k;
        cin >> n >> k;
        if (n >= k && (n - k) % 2 == 0) {
            cout << "YES ";
            cout << 1 + (n - k) << ' ';
            for (int i = 0; i < k - 1; ++i)
                cout << 1 << ' ';
            cout << endl;
        }   
        else if (n >= 2 * k && (n - 2 * k) % 2 == 0) {
            cout << "YES ";
            cout << 2 + (n - 2 * k) << ' ';
            for (int i = 0; i < k - 1; ++i)
                cout << 2 << ' ';
            cout << endl;
        }   
        else {
            cout << "NO" << endl;
        }   
    }   
}