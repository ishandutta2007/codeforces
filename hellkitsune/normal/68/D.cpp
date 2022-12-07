#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Node {
    int sum = 0;
    int l = -1, r = -1;
};

int h, qq;
char qt[10];
int v, e;
Node nodes[7777777];
int nodeCount = 1;
int q[33], qc;

double go(int v, double cur = 0) {
    int lSum = (nodes[v].l == -1) ? 0 : nodes[nodes[v].l].sum;
    int rSum = (nodes[v].r == -1) ? 0 : nodes[nodes[v].r].sum;
    if (lSum == rSum) return max(cur, (double)nodes[v].sum - lSum);
    if (lSum > rSum) return 0.5 * (max(cur, (double)nodes[v].sum - rSum) + go(nodes[v].l, max(cur, (double)nodes[v].sum - lSum)));
    return 0.5 * (max(cur, (double)nodes[v].sum - lSum) + go(nodes[v].r, max(cur, (double)nodes[v].sum - rSum)));
}

int main() {
    scanf("%d%d", &h, &qq);
    REP(query, qq) {
        scanf("%s", qt);
        if (qt[0] == 'a') {
            scanf("%d%d", &v, &e);
            qc = 0;
            while (v) {
                q[qc++] = v;
                v >>= 1;
            }
            nodes[0].sum += e;
            int curNode = 0;
            for (int i = qc - 2; i >= 0; --i) {
                if (q[i] == (q[i + 1] << 1)) {
                    if (nodes[curNode].l == -1) {
                        nodes[curNode].l = nodeCount++;
                    }
                    curNode = nodes[curNode].l;
                } else {
                    if (nodes[curNode].r == -1) {
                        nodes[curNode].r = nodeCount++;
                    }
                    curNode = nodes[curNode].r;
                }
                nodes[curNode].sum += e;
            }
        } else {
            printf("%.12f\n", go(0));
        }
    }
    return 0;
}