#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

bool query(ll x) {
    cout << "? " << x+1 << endl;
    char r; cin >> r;
    if (r == 'E') exit(0);
    return r == 'Y';
}

const int N = 1024;
int u[N];

// remove elements of u[y..y+k-1] which occur in u[x..x+k-1], or later in the y block
auto process_chunk(int k, int x, int y) {
    for (int i = x; i < x+k; i++)
        query(i);
    for (int i = y; i < y+k; i++)
        u[i] = u[i] && !query(i);
    cout << "R" << endl;
    for (int i = x+k-1; i >= x; i--)
        u[i] = u[i] && !query(i);
    for (int i = y+k-1; i >= y; i--)
        u[i] = u[i] && !query(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    fill(u, u+n, 1);
    for (int i = 0; i < n; i += k)
        for (int j = i+k; j < n; j += k)
            process_chunk(k, i, j);
    cout << "R" << endl;
    for (int i = 0; i < k; i++)
        u[i] = u[i] && !query(i);
    cout << "! " << accumulate(u, u+n, 0) << endl;
}