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
void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    bool have = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == k) {
            have = 1;
            a[i] = 1;
        }   
        else if (a[i] < k) {
            a[i] = 0;
        }
        else {
            a[i] = 2;
        }   
    }   

    if (!have) {
        cout << "no" << endl;
        return;
    }   

    if (n == 1) {
        cout << "yes" << endl;
        return;
    }   

    for (int i = 0; i + 1 < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 2; ++j)
            cnt += a[i + j] == 0;
        if (cnt < 1) {
            cout << "yes" << endl;
            return;
        }   
    }   

    for (int i = 0; i + 2 < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < 3; ++j)
            cnt += a[i + j] == 0;
        if (cnt < 2) {
            cout << "yes" << endl;
            return;
        }   
    }   

    cout << "no" << endl;
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
    while (t--)
        solve();
}