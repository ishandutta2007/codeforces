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

const int maxn = 200 * 1000 + 100;

int pa[maxn];
int pb[maxn];
int wherea[maxn];
int whereb[maxn];
int vala[maxn];
int valb[maxn];

int n;
int tc;

long long solve() {
    int lb = 0;
    int rb = n - 1;
    int midl = (lb + rb) / 2;
    int midr = midl + 1;

    for (int i = 0; i < n; i++) {
        vala[i] = -1;
        valb[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (vala[i] != -1) {
            continue;
        }

        int p = i;
        int len = 0;
        do {
            len++;
            p = whereb[pa[p]];
        } while (p != i);

        p = i;
        if (len % 2 == 1) {
            int val;
            if (midl + 1 >= n - midr) {
                val = midl;
                midl--;
            } else {
                val = midr;
                midr++;
            }
            vala[p] = val;
            valb[whereb[pa[p]]] = val;
            p = whereb[pa[p]];
        }
        for (int j = 0; j < len / 2; j++) {
            vala[p] = lb;
            valb[whereb[pa[p]]] = lb;
            lb++;
            p = whereb[pa[p]];

            vala[p] = rb;
            valb[whereb[pa[p]]] = rb;
            rb--;
            p = whereb[pa[p]];
        }
    }

    long long ans = 0ll;
    for (int i = 0; i < n; i++) {
  //      cerr << vala[i] << ' ' << valb[i] << endl;
        ans += abs(vala[i] - valb[i]);
    }

    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &pa[i]);
            pa[i]--;
            wherea[pa[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &pb[i]);
            pb[i]--;
            whereb[pb[i]] = i;
        }

        printf("%lld\n", solve());
    }

    return 0;
}