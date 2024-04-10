#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n;
int f[500000];
int k;
int a[300001], b[300001], c[300001];
bool g[500000];
int h[400001][2];
int w[400001];
bool good[400001];


int main() {
    cin >> n;
    for (int i = 0; i < 3 * n; i++) {
        int ff;
        scanf("%d", &ff);
        ff--;
        f[ff] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        a[i]--;
        b[i]--;
        c[i]--;
        vector<pair<int , int> > v;
        v.push_back(make_pair(f[a[i]], a[i]));
        v.push_back(make_pair(f[b[i]], b[i]));
        v.push_back(make_pair(f[c[i]], c[i]));
        sort(v.begin(), v.end());
        g[v[0].second] = true;
        w[v[0].second] = i;
        w[v[1].second] = i;
        w[v[2].second] = i;
        h[v[0].second][0] = min(v[1].second, v[2].second); 
        h[v[0].second][1] = max(v[1].second, v[2].second); 
    }
    cin >> k;
    k--;
    if (!g[k]) {
        // if (n == 100000) {
        //     cout << k << endl;
        //      cout << a[w[k]] + 1 << ' ' << b[w[k]] + 1 << ' ' << c[w[k]] + 1 << endl;
        //     cout << f[a[w[k]] + 1] << ' ' << f[b[w[k]] + 1] << ' ' << f[c[w[k]] + 1] << endl;
        // }
        for (int i = 0; i < 3 * n; i++) {
            if (i != k) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    } else {
        for (int j = 0; j < w[k]; j++) {
            good[a[j]] = true;
            good[b[j]] = true;
            good[c[j]] = true;
        }
        for (int j = 0; j < 3 * n; j++) {
            if (j <= h[k][1] && j != k && (good[j] || j == h[k][0] || j == h[k][1])) {
                printf("%d ", j + 1);
            }
        }
        for (int j = 0; j < 3 * n; j++) {
            if (j < h[k][1] && j != k && j != h[k][0] && !good[j]) {
                printf("%d ", j + 1);
            }
        }
         for (int j = 0; j < 3 * n; j++) {
            if (j > h[k][1] && j != k) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}