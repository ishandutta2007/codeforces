#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[2000], s[2000], rev[2000];
vector<PII> ans;
int tot = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", p + i), --p[i];
    REP(i, n) scanf("%d", s + i), --s[i];
    REP(i, n) rev[s[i]] = i;
    REP(i, n) p[i] = rev[p[i]];
    bool flag = true;
    while (flag) {
        flag = false;
        REP(i, n) if (p[i] < i) {
            flag = true;
            tot += i - p[i];
            int target = p[i], ind = i;
            for (int j = i - 1; j >= target; --j) if (p[j] > j) {
                swap(p[ind], p[j]);
                ans.pb(mp(ind + 1, j + 1));
                ind = j;
            }
            break;
        }
    }
    printf("%d\n%d\n", tot, (int)ans.size());
    for (PII x : ans) {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}