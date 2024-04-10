#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int Px, Py, Qx, Qy, n, m;
vector<pair<int, int> > m1, m2;

int sqr(int a) {
    return a*a;
}

bool checkin(double x0, double y0, double x1, double y1, double x2, double y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x0 > x1 - EPS && x0 < x2 + EPS && y0 > y1 - EPS && y0 < y2 + EPS) {
        return true;
    } else return false;
}

bool check() {
    for (int i = 0; i < m; i++) {
        int x0, y0, rr;
        x0 = Px + (m2[i].fs-Qx);
        y0 = Py + (m2[i].sc-Qy);
        rr = sqr(Px-Qx) + sqr(Py-Qy);
        for (int j = 0; j < n; j++) {
            double x1 = m1[j].fs-x0, y1 = m1[j].sc - y0;
            double x2 = m1[(j+1)%n].fs-x0, y2 = m1[(j+1)%n].sc - y0;
            double a=(y2-y1), b = (x1-x2), c = (-x1*(y2-y1)+y1*(x2-x1));
            double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
            if (c*c > rr*(a*a+b*b)+EPS)
                continue;
            else if (abs (c*c - rr*(a*a+b*b)) < EPS) {
                if (checkin(x0, y0, x1, y1, x2, y2)) {
                    return true;
                }
            }
            else {
                double d = rr - c*c/(a*a+b*b);
                double mult = sqrt (d / (a*a+b*b));
                double ax,ay,bx,by;
                ax = x0 + b * mult;
                bx = x0 - b * mult;
                ay = y0 - a * mult;
                by = y0 + a * mult;
                if (checkin(ax, ay, x1, y1, x2, y2)) {
                    return true;
                }
                if (checkin(bx, by, x1, y1, x2, y2)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> Px >> Py;
    cin >> n;
    m1.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> m1[i].fs >> m1[i].sc;
    }
    cin >> Qx >> Qy;
    cin >> m;
    m2.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> m2[i].fs >> m2[i].sc;
    }
    if (check()) {
        cout << "YES\n";
        return 0;
    }
    swap(Px, Qx);
    swap(Py, Qy);
    swap(n, m);
    swap(m1, m2);
    if (check()) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";

    return 0;
}