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
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

double g[410][410];
pair<int, int> _x[410];
int x[410], y[410];       
int phi[810];
double d[410];
int cnt[410];
int p[410];
int par2[410];
int par[410];
bool inq[410];
int n;


void go(int v) {
    if (par[v] == -1){
        return;
    }
    cnt[v]++;
    cnt[par[v]]--;
    p[par2[v]] = par[v];
    go(par[v]);
}


double solve() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) {
            d[i] = 0;
            par[i] = -1;
            inq[i] = true;
            q.push(i);
        } else {
            d[i] = 1e100;
        }
    }
    par[n] = -1;
    d[n] = 1e100;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        inq[v] = false;
        for (int i = v + 1; i < n; i++) {
            if ((y[i] < y[v]) && d[v] + g[v][i] - g[i][p[i]] < d[p[i]] - 1e-9) {
                d[p[i]] = d[v] + g[v][i] - g[i][p[i]];
                par[p[i]] = v;
                par2[p[i]] = i;
                if (!inq[p[i]]) inq[p[i]] = true, q.push(p[i]);
            }
        }
    }
    if (par[n] == -1){
        printf("-1\n");
        exit(0);
    }
    go(n);
    return d[n];
} 


int main() {
    if (n > 300) {
        cout << -1 << endl;
        return 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &_x[i].second, &_x[i].first);
    }
    sort(_x, _x + n);
    reverse(_x, _x + n);
    for (int i = 0;  i < n; i++){
        x[i] = _x[i].second;
        y[i] = _x[i].first;
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            g[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = n;
        cnt[i] = 2;
    }
    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += solve();
    }
    printf("%.15lf\n", (double)ans); 
    return 0;
}