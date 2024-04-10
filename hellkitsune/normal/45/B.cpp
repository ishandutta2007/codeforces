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

int n, m;
int g[100000], cnt[100000];
int v[100000], b[100000];
int s[100005], sc[100005], sz;
bool used[100005] = {}, dead[100005] = {}, marked[100005] = {};

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", g + i), --g[i], cnt[i] = 1;
    REP(i, m) scanf("%d", v + i);
    REP(i, m) scanf("%d", b + i);
    int prevAns = 0;
    REP(q, m) {
        int a = (v[q] + prevAns - 1) % n;
        int ans = 0;
        int rem = b[q];
        --rem;
        if (!used[a]) {
            ans = 1;
            used[a] = true;
        }
        while (true) {
            sz = 0;
            while (used[g[a]]) {
                if (marked[a] || dead[a]) break;
                s[sz] = a;
                marked[a] = true;
                rem -= cnt[a];
                a = g[a];
                ++sz;
            }
            if (marked[a] || dead[a]) {
                REP(i, sz) dead[s[i]] = true;
                REP(i, sz) marked[s[i]] = false;
                break;
            }
            REP(i, sz) marked[s[i]] = false;
            for (int i = sz - 1; i >= 0; --i) {
                cnt[s[i]] += cnt[g[s[i]]];
                g[s[i]] = g[g[s[i]]];
            }
            rem -= cnt[a];
            if (rem < 0) {
                break;
            }
            a = g[a];
            used[a] = true;
            ++ans;
        }
        printf("%d\n", ans);
        prevAns = ans;
    }
    return 0;
}