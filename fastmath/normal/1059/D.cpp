#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int MAXN = 1e5 + 7;

int n;
pair <double, double> a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    bool ch1 = 0, ch2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].second < 0) ch1 = 1;
        else ch2 = 1;
    }
    if (ch1 && ch2) {
        cout << "-1\n";
        exit(0);
    }
}

const double INF = 1e16;
const int IT = 100;

bool check(double r) {
    double tl = -INF, tr = INF;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i].second - r) > r) return 0;
        double d = sqrtl(r * r - (a[i].second - r) * (a[i].second - r));
        tl = max(tl, a[i].first - d);
        tr = min(tr, a[i].first + d);
    }   
    return tl <= tr;
}

double ans = INF;
void solve() {
    for (int i = 0; i < n; ++i) a[i].second = abs(a[i].second);

    double l = 0;
    double r = INF;
    for (int i = 0; i < IT; ++i) {
        double m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    ans = r;
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

    read();
    solve();
    print();

    return 0;
}