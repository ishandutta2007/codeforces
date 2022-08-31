#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

struct TPoint {
    long long x, y;

    TPoint(int x = 0, int y = 0)
        : x(x)
        , y(y)
    {
    }
};

TPoint p[100011];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lfloor(long long a, long long b);

long long lceil(long long a, long long b) {
    if (a < 0) {
        return -lfloor(-a, b);
    }
    return (a + b - 1) / b;
}

long long lfloor(long long a, long long b) {
    if (a < 0) {
        return -lceil(-a, b);
    }
    return a / b;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
    }
    p[N] = p[0];
    long long S = 0;
    for (int i = 0; i < N; ++i) {
        S += (p[i + 1].y + p[i].y) * (p[i + 1].x - p[i].x);
    }
    if (S > 0) {
        reverse(p, p + N);
        p[N] = p[0];
    }
    S = std::abs(S);
    long long bord = 0;

    for (int i = 0; i < N; ++i) {
        bord += gcd(abs(p[i + 1].x - p[i].x), abs(p[i + 1].y - p[i].y));
    }

    long long total = (S + bord + 2) / 2;

    vector<TPoint> low, high, left, right;
    int m = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i].x < p[m].x || (p[i].x == p[m].x && p[i].y < p[m].y)) {
            m = i;
        }
    }

    low.pb(p[m]);
    for (int i = m + 1; ; ++i) {
        i = (i + N) % N;
        if (p[i].x > p[(i + N - 1) % N].x) {
            low.pb(p[i]);
        } else {
            break;
        }
    }

    m = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i].x < p[m].x || (p[i].x == p[m].x && p[i].y > p[m].y)) {
            m = i;
        }
    }

    high.pb(p[m]);
    for (int i = m + N - 1; ; --i) {
        i = (i + N) % N;
        if (p[i].x > p[(i + 1) % N].x) {
            high.pb(p[i]);
        } else {
            break;
        }
    }

    m = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i].y < p[m].y || (p[i].y == p[m].y && p[i].x < p[m].x)) {
            m = i;
        }
    }

    left.pb(p[m]);
    for (int i = m + N - 1; ; --i) {
        i = (i + N) % N;
        if (p[i].y > p[(i + 1) % N].y) {
            left.pb(p[i]);
        } else {
            break;
        }
    }

    m = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i].y < p[m].y || (p[i].y == p[m].y && p[i].x > p[m].x)) {
            m = i;
        }
    }

    right.pb(p[m]);
    for (int i = m + 1; ; ++i) {
        i = (i + N) % N;
        if (p[i].y > p[(i + N - 1) % N].y) {
            right.pb(p[i]);
        } else {
            break;
        }
    }

    
    double ex2 = 0.0, ex = 0.0;
    
    {
        int li = 0, hi = 0;
        for (int x = -1000001; x <= 1000001; ++x) {
            if (x < low[0].x) {
                continue;
            }
            if (x > low.back().x) {
                break;
            }
            int l = low[li].y + lceil((x - low[li].x) * (low[li + 1].y - low[li].y), (low[li + 1].x - low[li].x));
            int r = high[hi].y + lfloor((x - high[hi].x) * (high[hi + 1].y - high[hi].y), (high[hi + 1].x - high[hi].x));
            int p = (r - l + 1);
            ex2 += (double)1.0 * p * x * x;
            ex += (double)1.0 * p * x;
            if (x == low[li + 1].x) {
                ++li;
            }
            if (x == high[hi + 1].x) {
                ++hi;
            }
        }
    }

    double ey2 = 0.0, ey = 0.0;
    {
        int li = 0, ri = 0;
        for (int y = -1000001; y <= 1000001; ++y) {
            if (y < left[0].y) {
                continue;
            }
            if (y > left.back().y) {
                break;
            }
            int l = left[li].x + lceil((y - left[li].y) * (left[li + 1].x - left[li].x), (left[li + 1].y - left[li].y));
            int r = right[ri].x + lfloor((y - right[ri].y) * (right[ri + 1].x - right[ri].x), (right[ri + 1].y - right[ri].y));
            int p = (r - l + 1);
            ey2 += (double)1.0 * p * y * y;
            ey += (double)1.0 * p * y;
            if (y == left[li + 1].y) {
                ++li;
            }
            if (y == right[ri + 1].y) {
                ++ri;
            }
        }
    }

    ex2 /= total;
    ex /= total;
    ey2 /= total;
    ey /= total;

    double ans = ex2 - ex * ex + ey2 - ey * ey;
    ans *= 1.0 * total / (total - 1);
    printf("%.10lf", (double)ans);

    return 0;
}