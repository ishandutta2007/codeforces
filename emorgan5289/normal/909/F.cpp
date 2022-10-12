#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<int> a(int n) {
    if (n == 0) return {};
    int x = (1<<(31-__builtin_clz(n)))-1;
    auto p = a(2*x-n);
    for (int i = 0; i < 2*n-2*x; i++)
        p.pb(n-i);
    return p;
}

vector<int> b(int n) {
    if (n == 6) return {3, 6, 2, 5, 1, 4};
    vector<int> p = {5, 3, 2, 7, 1, 4, 6};
    for (int i = 8; i <= n; i++)
        p.pb(__builtin_popcount(i) == 1 ? min(n, 2*i-1) : i-1);
    return p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n&1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        auto p = a(n);
        for (int i = 0; i < n; i++)
            cout << p[i] << " \n"[i==n-1];
    }
    if (n < 6 || __builtin_popcount(n) == 1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        auto p = b(n);
        for (int i = 0; i < n; i++)
            cout << p[i] << " \n"[i==n-1];
    }
}