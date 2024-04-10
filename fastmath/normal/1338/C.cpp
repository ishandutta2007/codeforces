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

ii solve(int a) {
    if (a == 0)
        return mp(0, 0);
    auto t = solve(a / 4);
    t.f <<= 2;
    t.s <<= 2;
    if (a % 4 == 0) {
    }   
    else if (a % 4 == 1) {
        t.f += 2;
        t.s += 3;
    }   
    else if (a % 4 == 2) {
        t.f += 3;
        t.s += 1;
    }   
    else {
        t.f += 1;
        t.s += 2;
    }   
    return t;
}   

void solve() {
    int n;
    cin >> n;
    int t = (n + 2) / 3;
    int pw = 1;
    while (pw < t) {
        t -= pw;
        pw *= 4;
    }       
    int a = pw + t - 1, b, c;

    if (n % 3 == 1) {
        cout << a << endl;
        return;
    }

    tie(b, c) = solve(a);
    if (n % 3 == 2)
        cout << b << endl;
    else
        cout << c << endl;
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