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
bool check(int x, vector <int> a) {
    for (int e : a)
        if (__gcd(e, x) > 1)
            return 0;
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    cout << (2 * (3 * n) - 1) * k << endl;
    vector <int> a;
    for (int i = 1; i <= 3 * n; ++i)
        a.app(2 * i - 1);
    for (int i = 0; i < a.size(); i += 3) {
        vector <int> v = {a[i], a[i + 1], a[i + 2]};
        if (check(a[i] + 1, v))
            v.app(a[i] + 1);
        else if (check(a[i] + 3, v))
            v.app(a[i] + 3);
        else
            exit(1);
        for (int e : v)
            cout << e * k << ' ';
        cout << endl;
    }   
}