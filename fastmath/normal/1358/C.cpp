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

int sum(int n) {
    return n * (n + 1) / 2;
}   
int get_mn(int n, int k) {
    return sum(k);
}
int get_mx(int n, int k) {
    return n * k - sum(k - 1);
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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int dx = x2 - x1;
        int dy = y2 - y1;
        int all = dx + dy;

        cout << get_mx(all, dx) - get_mn(all, dx) + 1 << endl;

    }   
}