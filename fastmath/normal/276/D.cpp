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
    const int LG = 61;
    int l, r;
    cin >> l >> r;
    for (int i = LG; i >= 0; --i)
        if (((l >> i) & 1) ^ ((r >> i) & 1)) {
            cout << (1ll << (i + 1)) - 1 << endl;
            exit(0);
        }   
    cout << 0 << endl;
}