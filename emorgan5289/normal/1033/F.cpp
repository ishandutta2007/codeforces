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

ll w, n, m;

vector<ll> transform(vector<ll> a, string s, bool inv) {
    for (int i = 0; i < w; i++) {

        if (s[i] == 'A' && !inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i))
                    a[j^(1<<i)] += a[j];
        if (s[i] == 'A' && inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i))
                    a[j^(1<<i)] -= a[j];

        if (s[i] == 'O' && !inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i))
                    a[j] += a[j^(1<<i)];
        if (s[i] == 'O' && inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i))
                    a[j] -= a[j^(1<<i)];

        if (s[i] == 'X' && !inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i)) {
                    a[j] += a[j^(1<<i)];
                    a[j^(1<<i)] = a[j]-2*a[j^(1<<i)];
                }
        if (s[i] == 'X' && inv)
            for (int j = 0; j < 1<<w; j++)
                if (j&(1<<i)) {
                    a[j^(1<<i)] = (a[j]+a[j^(1<<i)])/2;
                    a[j] -= a[j^(1<<i)];
                }
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w >> n >> m;
    vector<ll> a(1<<w);
    while (n--) {
        int x; cin >> x;
        a[x]++;
    }
    while (m--) {
        string s; cin >> s;
        reverse(all(s));
        int x = 0;
        for (int i = 0; i < w; i++)
            if (s[i] >= 'a')
                x |= 1<<i, s[i] += 'A'-'a';
        vector<ll> b = transform(a, s, 0);
        for (int i = 0; i < 1<<w; i++)
            b[i] *= b[i];
        cout << transform(b, s, 1)[x] << "\n";
    }
}