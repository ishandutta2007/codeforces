#include <bits/stdc++.h>

using namespace std;

int n, t, m[11], id[11];
double x[11], v[11], last[11], ans[11];

typedef pair<double, pair<int, int>> col;
set<col> events;

double pos(int i, double t) {
    return x[i] + (t - last[i]) * v[i];
}

double toc(int i, int j) {
    double rvel = v[i] - v[j];
    if(rvel <= 0) return DBL_MAX;
    double t = max(last[i], last[j]);
    return t + (pos(j, t) - pos(i, t)) / rvel;
}

int main() {
    scanf("%d %d", &n, &t);

    vector<vector<int>> inp;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        inp.push_back({a, b, c, i});
    }
    sort(inp.begin(), inp.end());

    for(int i = 0; i < n; i++) {
        x[i] = inp[i][0], v[i] = inp[i][1], m[i] = inp[i][2], id[i] = inp[i][3];
        if(i) {
            double f = toc(i-1, i);
            events.insert({f, {i-1, i}});
        }
    }

    while(1) {
        col ev = *events.begin();
        if(ev.first >= t) break;
        events.erase(ev);

        double tt = ev.first;
        int i = ev.second.first, j = ev.second.second;
        if(i) {
            double f = toc(i-1, i);
            events.erase({f, {i-1, i}});
        }
        if(j + 1 < n) {
            double f = toc(j, j + 1);
            events.erase({f, {j, j+1}});
        }

        double nv1, nv2;
        nv1 = ((m[i]-m[j])*v[i] + 2*m[j]*v[j])/(m[i] + m[j]);
        nv2 = ((m[j]-m[i])*v[j] + 2*m[i]*v[i])/(m[i] + m[j]);

        x[i] = x[j] = x[i] + (tt - last[i]) * v[i];
        last[i] = last[j] = tt;
        v[i] = nv1, v[j] = nv2;

        {
            double f = toc(i, j);
            events.insert({f, {i, j}});
        }
        if(i) {
            double f = toc(i-1, i);
            events.insert({f, {i-1, i}});
        }
        if(j + 1 < n) {
            double f = toc(j, j + 1);
            events.insert({f, {j, j+1}});
        }
    }

    for(int i = 0; i < n; i++) {
        int j = inp[i][3];
        ans[j] = x[i] + (t - last[i]) * v[i];
    }
    for(int i = 0; i < n; i++) {
        printf("%.9f\n", ans[i]);
    }
    return 0;
}