#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string.h>
#include <cmath>
#include <set>


using namespace std;



long long n, q;
vector<pair<int, int> > v[100000];
map<int, pair<int, int> > m;
map<int, double> m1;
map<pair<int, int>, double> ans;
int r[100000], w[100000];
bool used[100000];


int dfs(int u) {
    used[u] = true;
    int ans1 = 1;
    for (int j = 0; j < (int)v[u].size(); j++) {
        int g = v[u][j].first;
        if (!used[g]) {
            int s = dfs(g);
            ans[make_pair(u, g)] = s;
            ans[make_pair(g, u)] = s;
            ans1 += s;
        }
    }
    return ans1;
}


int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;b--;
        v[a].push_back(make_pair(b, l));
        v[b].push_back(make_pair(a, l));
        m[i] = make_pair(a, b);
        m1[i] = l;
    }
    dfs(0);
    double ans1 = 0.0;
    double count = n * (n - 1);
    for (int i = 0; i < n - 1; i++) {
        double t = ans[m[i]];
        double s = n - t;
       // cout << t << ' ' << s << endl;
        double l = m1[i];
        ans1 += ((t * s) / count) * l * 2.00;
        //cout << ans1 << endl;
    }
    //cout << ans1 << endl;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> r[i] >> w[i];
        double t = ans[m[r[i] - 1]];
        double s = n - t;
        double l = m1[r[i] - 1];
        ans1 -= (l - w[i]) * ((t * s) / count) * 2.00;
        m1[r[i] - 1] = w[i]; 
        printf("%.10lf\n", ans1 * 3);
    }
    return 0;
}