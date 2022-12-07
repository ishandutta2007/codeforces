#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int ask(int x, int y, int xx, int yy) {
    cout << "? " << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
    int res;
    cin >> res;
    return res;
}

void solve(int x, int y, int xx, int yy, int fx, int fy, int fxx, int fyy) {
    int sx = x, sy = y, sxx = xx, syy = yy;
    if (fx < xx && ask(fx + 1, y, xx, yy) == 1) {
        sx = fx + 1;
    } else if (fy < yy && ask(x, fy + 1, xx, yy) == 1) {
        sy = fy + 1;
    } else if (fxx > x && ask(x, y, fxx - 1, yy) == 1) {
        sxx = fxx - 1;
    } else {
        syy = fyy - 1;
    }

    int lo = sx, hi = sxx, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(mid, sy, sxx, syy) == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    sx = lo;

    lo = sy, hi = syy;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(sx, mid, sxx, syy) == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    sy = lo;

    lo = sx, hi = sxx;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(sx, sy, mid, syy) == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    sxx = lo;

    lo = sy, hi = syy;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(sx, sy, sxx, mid) == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    syy = lo;

    cout << "! " << fx << ' ' << fy << ' ' << fxx << ' ' << fyy << ' ' << sx << ' ' << sy << ' ' << sxx << ' ' << syy << endl;
}

int main() {
    cin >> n;

    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(mid, 1, n, n) == 2) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int xfrom = lo;

    lo = 1, hi = n;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(1, mid, n, n) == 2) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int yfrom = lo;

    lo = 1, hi = n;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(1, 1, mid, n) == 2) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int xto = lo;

    lo = 1, hi = n;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(1, 1, n, mid) == 2) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int yto = lo;

    int x = xfrom, y = yfrom;
    int xx = xto, yy = yto;

    int oxx = xx, oyy = yy;
    if (x < xx && ask(x, y, xx - 1, yy) == 1) --xx;
    else --yy;

    lo = x, hi = xx;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(x, y, mid, yy) == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int nxx = lo;

    lo = x, hi = nxx;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(mid, y, nxx, yy) == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int nx = lo;

    lo = y, hi = yy;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (ask(x, mid, nxx, yy) == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int ny = lo;

    lo = ny, hi = yy;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (ask(x, ny, nxx, mid) == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    int nyy = lo;

    solve(x, y, oxx, oyy, nx, ny, nxx, nyy);
}