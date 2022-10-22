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

const int N = 2e5 + 7;
int n, l, x, y;
int a[N];
bool check(int x) {
    int i = lower_bound(a, a + n, x) - a;
    if (i < n && a[i] == x)
        return 1;
    return 0;
}   
bool check(int p, int x) {
    return check(p - x) || check(p + x);
}   

bool used[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> l >> x >> y;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    for (int i = 0; i < n; ++i) {
        used[0] |= check(a[i], x);
        used[1] |= check(a[i], y);
    }   
    if (used[0] && used[1]) {
        cout << "0\n";
        exit(0);
    }   
    if (used[0] || used[1]) {
        cout << "1\n";
        if (used[0])
            cout << y << endl;
        else
            cout << x << endl;
        exit(0);
    }   
    vector <int> d = {-x, x, -y, y};
    for (int i = 0; i < n; ++i) {
        for (auto e : d) {
            int to = a[i] + e;
            if (0 <= to && to <= l && check(to, x) && check(to, y)) {
                cout << "1\n";
                cout << to << endl;
                exit(0);
            }   
        }   
    }   
    cout << "2\n";
    cout << x << ' ' << y << endl;
}