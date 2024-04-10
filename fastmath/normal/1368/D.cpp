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

    int n;
    cin >> n;

    const int LG = 20;

    vector <int> a(n), have(LG);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int bit = 0; bit < LG; ++bit) {
            if ((a[i] >> bit) & 1)
                ++have[bit];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int add = 0;

        for (int bit = 0; bit < LG; ++bit) {
            if (have[bit]) {
                add += 1 << bit;
                --have[bit];
            }   
        }   

        ans += add * add;
    }   
    cout << ans << endl;
}