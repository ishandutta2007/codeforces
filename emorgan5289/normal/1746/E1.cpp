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

int q = 0;

bool query(const vector<int> x) {
    cout << "? " << x.size();
    for (int i = 0; i < x.size(); i++)
        cout << " " << x[i];
    cout << endl;
    q++;
    string r; cin >> r;
    return r == "YES";
}

bool submit(const int x) {
    cout << "! " << x << endl;
    string r; cin >> r;
    return r == ":)";
}

vector<int> operator+(vector<int> x, vector<int> y) {
    for (int i : y) x.pb(i);
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> b(n);
    iota(all(b), 1);

    debug(b.size());

    while (b.size() > 3) {
        array<vector<int>, 4> a;
        for (int i = 0; i < b.size(); i++)
            a[i%4].pb(b[i]);
        bool x = query(a[0] + a[1]);
        bool y = query(a[0] + a[2]);
        if (x && y)
            b = a[0] + a[1] + a[2];
        if (!x && y)
            b = a[0] + a[2] + a[3];
        if (x && !y)
            b = a[0] + a[1] + a[3];
        if (!x && !y)
            b = a[1] + a[2] + a[3];
        debug(b.size());
    }

    if (b.size() == 3) {
        bool x = query({b[0]});
        bool y = query({b[1]});
        bool z = query({b[1]});
        bool w = query({b[0]});

        if (x && y)
            b = {b[0], b[1]};
        else if (x && !y)
            b = {b[0], b[2]};
        else if (!x && y)
            b = {b[1], b[2]};
        // x, y false
        else if (!z)
            b = {b[0], b[2]};
        else if (w)
            b = {b[0], b[1]};
        else if (!w)
            b = {b[1], b[2]};
        else
            assert(false);

    }

    debug(b, q);

    if (!submit(b[0]))
        submit(b[1]);
}