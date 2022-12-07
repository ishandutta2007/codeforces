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

int n, s;
vector<PII> v[100];
int ans = 0;

int main() {
    scanf("%d%d", &n, &s);
    REP(i, n) {
        int k;
        scanf("%d", &k);
        int dist = 0, tot = 0;
        v[i].pb(mp(0, 0));
        REP(j, k) {
            int a, b;
            scanf("%d%d", &a, &b);
            dist += a * b;
            tot += b;
            v[i].pb(mp(dist, tot));
        }
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        vector<PII> &p = v[i];
        vector<PII> &q = v[j];
        int ps = (int)p.size();
        int qs = (int)q.size();
        int pi = 1, qi = 1;
        bool pw = p[1].first / p[1].second > q[1].first / q[1].second;
        int prevDist = 0;
        while (pi < ps && qi < qs) {
            if (p[pi].first < q[qi].first) {
                int dist = p[pi].first;
                if (dist == prevDist) {
                    ++pi;
                    continue;
                }
                prevDist = dist;
                int t = p[pi].second;
                int qdist = q[qi].first - q[qi - 1].first;
                LL qt = (LL)q[qi - 1].second * qdist + LL(q[qi].second - q[qi - 1].second) * (dist - q[qi - 1].first);
                if (pw && qt < (LL)t * qdist) {
                    pw = false;
                    ++ans;
                } else if (!pw && (LL)t * qdist < qt) {
                    pw = true;
                    ++ans;
                }
                ++pi;
            } else {
                int dist = q[qi].first;
                if (dist == prevDist) {
                    ++qi;
                    continue;
                }
                prevDist = dist;
                int t = q[qi].second;
                int pdist = p[pi].first - p[pi - 1].first;
                LL pt = (LL)p[pi - 1].second * pdist + LL(p[pi].second - p[pi - 1].second) * (dist - p[pi - 1].first);
                if (pw && (LL)t * pdist < pt) {
                    pw = false;
                    ++ans;
                } else if (!pw && pt < (LL)t * pdist) {
                    pw = true;
                    ++ans;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}