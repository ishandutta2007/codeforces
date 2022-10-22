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

const int N = 2007;
int n;
int a[N];

bool small(double x) {
    for (int i = 1; i <= n; ++i) {
        if ((int)(x * i) == a[i])
            continue;
        if ((int)(x * i) < a[i])
            return 1;
        if ((int)(x * i) > a[i])
            return 0;
    }   
    return 0;
}   

bool big(double x) {
    for (int i = 1; i <= n; ++i) {
        if ((int)(x * i) == a[i])
            continue;
        if ((int)(x * i) < a[i])
            return 0;
        if ((int)(x * i) > a[i])
            return 1;
    }   
    return 0;
}   

int get(double x) {
    return (int)(x * (n + 1));
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i]; 

    const double EPS = 1e-8;

    double l = 0, r = 1e9;
    for (int t = 0; t < 100; ++t) {
        double m = (l + r) / 2;
        if (small(m))
            l = m;
        else
            r = m;
    }   
    auto res_l = r + EPS;
    l = 0, r = 1e9;
    for (int t = 0; t < 100; ++t) {
        double m = (l + r) / 2;
        if (big(m))
            r = m;
        else
            l = m;
    }   
    auto res_r = l - EPS;
    /*
    cout << res_l << ' ' << res_r << endl;
    cout << get(res_l) << ' ' << get(res_r) << endl;
    */
    if (get(res_l) == get(res_r)) {
        cout << "unique\n";
        cout << get(res_l) << endl;
    }   
    else {
        cout << "not unique\n";
    }   
}