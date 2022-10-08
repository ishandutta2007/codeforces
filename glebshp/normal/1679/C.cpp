#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int inf = 1000 * 1000 * 1000;

struct TRmq {
    int total_elems;
    int shift;
    vector <int> body;

    TRmq(int n) {
        int k = 1;
        while (k < n) {
            k *= 2;
        }
        total_elems = k * 2;
        shift = k;
        body.resize(total_elems);
    }

    void Add(int p, int x) {
        p += shift;
        body[p] += x;
        while (p > 1) {
//            cerr << "change " << p << ' ' << x << endl;
            p /= 2;
            body[p] = min(body[p * 2], body[p * 2 + 1]);
        }
    }

    GetMin(int i, int j) {
        return RangeQuery(1, i + 1, j + 1, 1, shift);
    }

    int RangeQuery(int v, int i, int j, int lb, int rb) {
        //cerr << v << ' ' << body[v] << ' ' << i << ' ' << j << ' ' << lb << ' ' << rb << endl;
        if (i > rb || j < lb) {
            return inf;
        }
        if (lb >= i && rb <= j) {
            return body[v];
        }
        return min(RangeQuery(v * 2, i, j, lb, (lb + rb) / 2), RangeQuery(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb));
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);
    TRmq hrmq(n);
    TRmq vrmq(n);

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            hrmq.Add(x, 1);
            vrmq.Add(y, 1);
        } else if (t == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            hrmq.Add(x, -1);
            vrmq.Add(y, -1);
        } else {
            int xu, yl, xd, yr;
            scanf("%d%d%d%d", &xu, &yl, &xd, &yr);
            xu--, yl--, xd--, yr--;
//            cerr << hrmq.GetMin(xu, xd) << ' ' << vrmq.GetMin(yl, yr) << endl;
            if (max(hrmq.GetMin(xu, xd), vrmq.GetMin(yl, yr)) == 0) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
        }
    }

    return 0;
}