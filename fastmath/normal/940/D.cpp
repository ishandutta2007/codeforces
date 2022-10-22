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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    string b;
    cin >> b;

    const int INF = 1e9;
    int r = INF, l = -INF;
    for (int i = 4; i < n; ++i) {
        if (b[i] != b[i - 1]) {
            if (b[i] == '0') {
                for (int j = i - 4; j <= i; ++j)
                    r = min(r, a[j] - 1);
            }   
            else {
                for (int j = i - 4; j <= i; ++j)
                    l = max(l, a[j] + 1);
            }   
        }
    }   
    cout << l << ' ' << r << '\n';
}