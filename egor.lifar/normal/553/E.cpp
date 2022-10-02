#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


using namespace std;

#define F first
#define S second
#define MP make_pair
const int MAXN = 55;
const int MAXM = 105;
const int MAXT = 20202;
const int MAXF = 32768;
const double INF = 1E20;
const double PI = acos(-1);
const complex<double> I(0, 1);
int n, m, T, x;
vector<int> redge[MAXN];
double dp[MAXN][MAXT];
int res[MAXM], rev[MAXM], rec[MAXM];
double prob[MAXM][MAXT];
double probsum[MAXM][MAXT];
complex<double> four_a[MAXF], four_b[MAXF];
vector<double> conv[MAXM][16];
complex<double> uroot[MAXF];


void make_uroot() {
    for(int i = 0; i < MAXF; i++) {
        uroot[i] = exp(2 * PI * i / MAXF * I);
    }
}


void fft(int n, complex<double> a[], bool inv = false) {
    int lv = MAXF / n;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            complex<double> w = uroot[i * lv];
            if (inv) {
                w = conj(w);
            }
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                complex<double> x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        lv *= 2;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) {
            swap(a[i], a[j]);
        }
    }
}

void shortest_path() {
    for (int i = 0; i < n - 1; i++) {
        for (int t = 0; t <= T + 1; t++) {
            dp[i][t] = INF;
        }
    }
    dp[n - 1][T + 1] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(x, n - 1));
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second, c = p.first;
        if (dp[v][T + 1] != INF) {
            continue;
        }
        dp[v][T + 1] = c;
        for (int i = 0; i < (int)redge[v].size(); i++) {
            int ed = redge[v][i];
            int u = rev[ed], nc = rec[ed];
            pq.push(make_pair(c + nc + 0.5, u));
        }
    }
}


void make_conv(int m, int lv) {
    int len = (1 << lv) * 2;
    conv[m][lv].clear();
    fft(len, four_a);
    fft(len, four_b);
    for (int i = 0; i< len; i++) {
        four_a[i] = four_a[i] * four_b[i];
    }
    fft(len, four_a, true);
    for (int i = 0; i < len; i++) {
        conv[m][lv].push_back(four_a[i].real() / len);
    }
}


int main() {
    make_uroot();
    scanf("%d %d %d %d", &n, &m, &T, &x);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        redge[b].push_back(i);
        res[i] = b;
        rev[i] = a;
        rec[i] = c;
        for (int j = 1; j <= T; j++) {
            scanf("%lf", &prob[i][j]);
            prob[i][j] *= 1e-5;
        }
        probsum[i][T + 1] = 0;
        for (int j = T; j >= 0; j--) {
            probsum[i][j] = probsum[i][j + 1] + prob[i][j];
        }
    }
    shortest_path();
    for (int t = T; t >= 0; t--) {
        for (int i = 0; i < m; i++) {
            int u = res[i], v = rev[i];
            double val = probsum[i][T - t + 1] * dp[u][T + 1] + rec[i];
            int len = T - t;
            int lb = len & (-len);
            for (int j = 0; j < 2 * lb; j++) {
                four_a[j] = (j < lb ? dp[u][t + lb - j] : 0.);
                four_b[j] = (j + 1 <= T ? prob[i][j + 1] : 0.);
            }
            if (lb > 0) {
                make_conv(i, __lg(lb));
            }
            int nowlen = len - 1;
            for (int j = 16; j >= 0; j--) {
                if (len & (1 << j)) {
                    val += conv[i][j][nowlen];
                    nowlen -= (1 << j);
                }
            }
            dp[v][t] = min(dp[v][t], val);
        }
    }
    double ans = dp[0][0];
    printf("%.10f\n", ans);
    return 0;
}