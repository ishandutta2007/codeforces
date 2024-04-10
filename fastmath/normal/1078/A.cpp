#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1e18 + 7;

double r1[2], r2[2];
pair <double, double> p1[2], p2[2];

double getr(pair <double, double> a, pair <double, double> b) {
    return hypot(abs(a.first - b.first), abs(a.second - b.second));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);

    int a, b, c;
    cin >> a >> b >> c;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double ans = abs(x1 - x2) + abs(y1 - y2);

    if (a == 0) {
        if (a * x1 + b * y1 + c == 0) {
            r1[0] = 0;
            p1[0] = {x1, y1};
        }
        else {
            r1[0] = INF;
            p1[0] = {0, 0};
        }
        if (a * x2 + b * y2 + c == 0) {
            r2[0] = 0;
            p2[0] = {x2, y2};
        }
        else {
            r2[0] = INF;
            p2[0] = {0, 0};
        }   
    }   
    else {
        double px1 = (double)(-c - b*y1) / a;
        double py1 = y1;
        r1[0] = abs(px1 - x1) + abs(py1 - y1);
        p1[0] = {px1, py1};

        double px2 = (double)(-c - b*y2) / a;
        double py2 = y2;
        r2[0] = abs(px2 - x2) + abs(py2 - y2);
        p2[0] = {px2, py2};
    }

    if (b == 0) {
        if (a * x1 + b * y1 + c == 0) {
            r1[1] = 0;
            p1[1] = {x1, y1};
        }
        else {
            r1[1] = INF;
            p1[1] = {0, 0};
        }
        if (a * x2 + b * y2 + c == 0) {
            r2[1] = 0;
            p2[1] = {x2, y2};
        }
        else {
            r2[1] = INF;
            p2[1] = {0, 0};
        }   
    }   
    else {
        double py1 = (double)(-c - a*x1) / b;
        double px1 = x1;
        r1[1] = abs(px1 - x1) + abs(py1 - y1);
        p1[1] = {px1, py1};

        double py2 = (double)(-c - a*x2) / b;
        double px2 = x2;
        r2[1] = abs(px2 - x2) + abs(py2 - y2);
        p2[1] = {px2, py2};
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans = min(ans, r1[i] + r2[j] + getr(p1[i], p2[j]));
        }   
    }   

    cout << ans << '\n';

    return 0;
}