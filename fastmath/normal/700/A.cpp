#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1e9 + 7;

int n, l, v1, v2, k;

bool check(double t) {
    if (v1 * t > l) return 1;
    if (v2 * t < l) return 0;
    
    //v2 * want + v1 * (t - want) = l
    //v2 * want - v1 * want + v1 * t = l
    //want * (v2 - v1) + v1 * t = l
    //want = (l - v1 * t) / (v2 - v1)

    double want = (l - v1 * t) / (v2 - v1); 
    double curr = 0;
    int gr = (n - 1) / k + 1;
    double pos = 0;
    for (int i = 0; i < gr; ++i) {
        pos += want * v1;
        curr += want;
        if (i == gr - 1) return curr < t;
        double add = (want * (v2 - v1)) / (v2 + v1);
        pos += add * v1;
        curr += add;
    }   

    exit(1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

    cin >> n >> l >> v1 >> v2 >> k;

    double tl = 0;
    double tr = INF;
    for (int i = 0; i < 100; ++i) {
        double tm = (tl + tr) / 2;
        if (check(tm)) tr = tm;
        else tl = tm;
    }

    cout << tr << '\n';
    return 0;   
}