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
typedef vector<vector<int> > State;

vector<State> p, q;
int n;

int main() {
    scanf("%d", &n);
    p.pb(vector<vector<int> >(1, vector<int>(1, 1)));
    for (int i = 2; i <= n; ++i) {
        bool rev = false;
        for (State &x : p) {
            if (rev) {
                State res = x;
                res.pb(vector<int>(1, i));
                q.pb(res);
                for (int j = (int)x.size() - 1; j >= 0; --j) {
                    State res = x;
                    res[j].pb(i);
                    q.pb(res);
                }
            } else {
                REP(j, x.size()) {
                    State res = x;
                    res[j].pb(i);
                    q.pb(res);
                }
                State res = x;
                res.pb(vector<int>(1, i));
                q.pb(res);
            }
            rev = !rev;
        }
        p = q;
        q.clear();
    }
    printf("%d\n", (int)p.size());
    for (State &x : p) {
        bool frst = true;
        for (vector<int> &y : x) {
            if (!frst) {
                printf(",");
            }
            frst = false;
            printf("{");
            REP(i, (int)y.size() - 1) printf("%d,", y[i]);
            printf("%d}", y.back());
        }
        printf("\n");
    }
    return 0;
}