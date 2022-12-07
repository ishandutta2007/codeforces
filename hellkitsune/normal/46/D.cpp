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

int L, b, f;
int len[100], pos[100], n;
vector<int> cand;

int main() {
    scanf("%d%d%d%d", &L, &b, &f, &n);
    REP(i, n) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%d", len + i);
            if (len[i] <= L) {
                cand.pb(0);
            }
            REP(j, i) if (pos[j] != -1 && pos[j] + len[j] + b + len[i] <= L) {
                cand.pb(pos[j] + len[j] + b);
            }
            sort(cand.begin(), cand.end());
            pos[i] = -1;
            for (int x : cand) {
                int from = x - b;
                int to = x + f + len[i];
                bool ok = true;
                REP(j, i) if (pos[j] != -1 && from < pos[j] + len[j] && pos[j] < to) {
                    ok = false;
                    break;
                }
                if (ok) {
                    pos[i] = x;
                    break;
                }
            }
            cand.clear();
            printf("%d\n", pos[i]);
        } else {
            pos[i] = -1;
            int x;
            scanf("%d", &x), --x;
            pos[x] = -1;
        }
    }
    return 0;
}