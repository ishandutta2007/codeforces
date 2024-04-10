#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; fin >> n >> k;
    vector<bool> a(n), b(n), c(n), d(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        char x; fin >> x; a[i] = x == 'W';
    }
    int g = -1;
    for (int i = 0; i < n; i++) {
        b[i] = a[i] == a[(i+1)%n];
        if (b[i]) g = i;
    }
    if (g == -1) {
        for (int i = 0; i < n; i++)
            cout << (a[i] == (k%2 == 0) ? 'W' : 'B');
        cout << "\n"; return 0;
    }
    l[g] = r[g] = 0;
    for (int i = (g+1)%n; i != g; i = (i+1)%n)
        l[i] = (b[i] ? 0 : l[(i-1+n)%n]+1);
    for (int i = (g-1+n)%n; i != g; i = (i-1+n)%n)
        r[i] = (b[i] ? 0 : r[(i+1)%n]+1);
    for (int i = 0; i < n; i++)
        c[i] = b[i] || (min(l[i], r[i]) <= k && l[i] != r[i]);
    d[g] = a[g];
    for (int i = (g-1+n)%n; i != g; i = (i-1+n)%n)
        d[i] = c[i] == d[(i+1)%n];
    for (int i = 0; i < n; i++)
        cout << (d[i] ? 'W' : 'B');
    cout << "\n";
}