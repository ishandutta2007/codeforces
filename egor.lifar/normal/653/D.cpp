#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


long long n, m, x;
vector<pair<long long, long long> > v[51];
const long long inf = 1000 * 1000 * 1000 * 1000LL;


void push(long long u, long long v, vector<vector<long long> >  & f, vector<long long>  & e, const vector<vector<long long> >  & c) {
    long long d = min(e[u], c[u][v] - f[u][v]);
    f[u][v] += d;
    f[v][u] = - f[u][v];
    e[u] -= d;
    e[v] += d;
}


void lift(long long u, vector<long long>  & h, const vector<vector<long long> >  & f, const vector<vector<long long> >  & c) {
    long long d = inf;
    for (int i = 0; i < (long long)f.size(); i++)
        if (c[u][i] - f[u][i] > 0) {
            d = min(d, h[i]);
        }
    if (d == inf) {
        return;
    }
    h[u] = d + 1;
}


bool get(double s) {
    vector<vector<long long> > c;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        c[i].resize(n);
        for (long long j = 0; j < (long long)v[i].size(); j++) {
            c[i][v[i][j].first] = (long long)floor(double(v[i][j].second) / double(s / double(x)) + 1e-9);
        }
    }
    vector<vector<long long> >  f (n, vector<long long> (n));
    for (int i = 1; i < n; i++) {
        f[0][i] = c[0][i];
        f[i][0] = -c[0][i];
    }
    vector<long long> h(n);
    h[0] = n;
    vector<long long> e(n);
    for (int i = 1; i < n; i++) {
        e[i] = f[0][i];
    }
    while (true)  {
        int i;
        for (i = 1; i < n - 1; i++) {
            if (e[i] > 0) {
                break;
            }
        }
        if (i == n - 1) {
            break;
        }
        long long j;
        for (j = 0; j < n; j++) {
            if (c[i][j] - f[i][j] > 0 && h[i] == h[j] + 1) {
                break;
            }
        }
        if (j < n) {
            push(i, j, f, e, c);
        } else {
            lift(i, h, f, c);
        }
    }
    long long flow = 0;
    for (int i = 0; i < n; i++) {
        flow += f[0][i];
    }
    return flow >= x;
}


int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;b--;
        v[a].push_back(make_pair(b, c));
    }
    double l = 1e-9;
    double r = n * 10000000LL + 1;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2.0;
        if (get(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.7lf\n", l);
    return 0;   
}