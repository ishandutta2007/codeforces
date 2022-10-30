#include <iostream>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define eb emplace_back

#define next _next
#define prev _prev
#define hash _hash
#define all(s) s.begin(), s.end()

typedef long long ll;
typedef long double ld;
//typedef complex<double> cd;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-13;

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

const double PI = acos(-1);

const int N = 200200;

int n, m, k, rev[3 * N], p = 1, pn = 0;
char s[N], t[N];
char letters[5] = "ATGC";
bool bad[N];

double ax[3 * N], bx[3 * N], cx[3 * N], ay[3 * N], by[3 * N], cy[3 * N];

void FFT(double * Ax, double * Ay, bool to_reverse) {
    for (int i = 0; i < p; i++) {
        if (rev[i] < i) {
            swap(Ax[i], Ax[rev[i]]);
            swap(Ay[i], Ay[rev[i]]);
        }
    }

    for (int l = 1; l < p; l <<= 1) {
        double angle = 2 * PI / (l << 1);
        double cx = cos(angle), cy = (to_reverse ? -sin(angle) : sin(angle));
        for (int i = 0; i < p; i += (l << 1)) {
            double cur_x = 1, cur_y = 0;
            for (int id = i; id < i + l; id++) {
                double bx = cur_x * Ax[id + l] - cur_y * Ay[id + l];
                double by = cur_x * Ay[id + l] + cur_y * Ax[id + l];
                Ax[id + l] = Ax[id] - bx;
                Ay[id + l] = Ay[id] - by;
                Ax[id] = Ax[id] + bx;
                Ay[id] = Ay[id] + by;
                double cur_x2 = cur_x * cx - cur_y * cy;
                cur_y = cur_x * cy + cur_y * cx;
                cur_x = cur_x2;
                if (abs(Ax[id]) < EPS) Ax[id] = 0;
                if (abs(Ay[id]) < EPS) Ay[id] = 0;
                if (abs(Ax[id + l]) < EPS) Ax[id + l] = 0;
                if (abs(Ay[id + l]) < EPS) Ay[id + l] = 0;
                if (abs(cur_x) < EPS) cur_x = 0;
                if (abs(cur_y) < EPS) cur_y = 0;
            }
        }
    }
}

void mult() {
    memset(ay, 0, p * sizeof(double));
    memset(by, 0, p * sizeof(double));
    FFT(ax, ay, false);
    FFT(bx, by, false);
    for (int i = 0; i < p; i++) {
        cx[i] = ax[i] * bx[i] - ay[i] * by[i] + cx[i];
        cy[i] = ax[i] * by[i] + ay[i] * bx[i] + cy[i];
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", s, t);
    reverse(t, t + m);
    while (p < n) {
        p <<= 1;
        pn++;
    }

    p <<= 1;
    pn++;

    for (int i = 0; i < p; i++) {
        for (int j = 0, k = 1; k < p; j++, k <<= 1) {
            if (i & k) {
                rev[i] |= (1 << (pn - j - 1));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == letters[j]) {
                s[i] = j;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            if (t[i] == letters[j]) {
                t[i] = j;
            }
        }
    }
    for (int ch = 0; ch < 4; ch++) {
        int last = -INF;
        for (int i = 0; i < p; i++) {
            ax[i] = (i < n);
            bx[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == ch) {
                last = i;
            }
            if (i - last <= k) {
                ax[i] = 0;
            }
        }
        last = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ch) {
                last = i;
            }
            if (last - i <= k) {
                ax[i] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            if (t[i] == ch) {
                bx[i] = 1;
            }
        }

        //mout(a, a + n);
        //mout(b, b + m);

        mult();
    }
    FFT(cx, cy, true);

    int ans = n - m + 1;
    for (int i = m - 1; i < n; i++) {
        if ((int) round(cx[i]) != 0) {
            ans--;
        }
    }
    printf("%d", ans);
	return 0;
}