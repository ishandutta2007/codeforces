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
#include <vector>
#include <unordered_map>


using namespace std;


int n, q;
vector<int> pos[300001];
int sum = 0;
int d[1300001];
int num = 0;


void change(int i, int x) {
    d[i] = x;
    while (i / 2 > 0) {
        i /= 2;
        d[i] = d[i * 2] + d[i * 2 + 1];
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    return rmq(v * 2, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int main() {
    cin >> n >> q;
    vector<int> stack;
    int ss = 1;
    while (ss < q) {
        ss *= 2;
    }
    int r = 0;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            x--;
            change(ss + num, 1);
            pos[x].push_back(num);
            sum++;
            num++;
        } else {
            if (t == 2) {
                int x;
                scanf("%d", &x);
                x--;
                for (int j = 0; j < (int)pos[x].size(); j++) {
                    if (pos[x][j] >= r) {
                        sum--;
                    }
                    change(ss + pos[x][j], 0);
                }
                pos[x].clear();
            } else {
                int tt;
                scanf("%d", &tt);
                sum -= rmq(1, 1, ss, r + 1, tt);
                r = max(r, tt);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}