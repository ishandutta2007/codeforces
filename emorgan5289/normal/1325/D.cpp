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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll u, v; cin >> u >> v;
    if (u == 0 && v == 0)
        return cout << "0\n\n", 0;
    if (u == v)
        return cout << "1\n" << u << "\n", 0;
    if (v > u && (v-u)%2 == 0 && (((v-u)/2)&u) == 0)
        return cout << "2\n" << (v-u)/2 << " " << (v+u)/2 << "\n", 0;
    if (v > u && (v-u)%2 == 0)
        return cout << "3\n" << (v-u)/2 << " " << (v-u)/2 << " " << u << "\n", 0;
    cout << "-1\n";
}