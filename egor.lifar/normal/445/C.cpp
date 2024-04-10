#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <stack>


using namespace std;


int n, m;
vector< pair<int, int> > v[500];
int a[500];
double ans = 0.000000;



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        v[x - 1].push_back(make_pair(y - 1, c));
        v[y - 1].push_back(make_pair(x - 1, c));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            ans = max(ans, double(a[i] + a[v[i][j].first]) / double(v[i][j].second));
        }
    }
    printf("%.15lf\n", ans);
    return 0;
}