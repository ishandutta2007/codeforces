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


using namespace std;


int n, m, k;
pair<int, int> g[5001], r[5001];


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        g[i] = make_pair(0, -1);
    }
    for (int i = 0; i < m; i++) {
        r[i] = make_pair(0, -1);
    }
    for (int i = 0; i < k; i++) {
        int t, c, a;
        scanf("%d %d %d", &t, &c, &a);
        c--;
        if (t == 1) {
            g[c] = make_pair(a, i);
        } else {
            r[c] = make_pair(a, i);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i].second > r[j].second) {
                printf("%d ", g[i].first);
            } else {
                printf("%d ", r[j].first);
            }
        }
        printf("\n");
    }
    return 0;
}