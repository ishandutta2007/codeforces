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
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    for (int i = 0; i + 1 < n; ++i) {
        int sum = a[i] ^ a[i + 1];
        if (i + 2 < n && sum > a[i + 2]) {
            cout << 1 << endl;
            exit(0);
        }   
        if (i && sum < a[i - 1]) {
            cout << 1 << endl;
            exit(0);
        }   
    }   

    for (int i = 0; i + 2 < n; ++i) {
        int sum = a[i] ^ a[i + 1] ^ a[i + 2];
        if (i + 3 < n && sum > a[i + 3]) {
            cout << 2 << endl;
            exit(0);
        }   
        if (i && sum < a[i - 1]) {
            cout << 2 << endl;
            exit(0);
        }   
    }   

    assert(n <= 100);

    const int INF = 1e18;

    // i - right in left side
    int ans = INF;
    for (int i = 0; i + 1 < n; ++i) {
        int lsum = 0;
        for (int l = i; l >= 0; --l) {
            lsum ^= a[l];

            int rsum = 0;
            for (int r = i + 1; r < n; ++r) {
                rsum ^= a[r];
                if (rsum < lsum) {
                    int len = r - l + 1;
                    assert(len >= 2);
                    ans = min(ans, len - 2);
                }   
            }
        }   
    }   

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}