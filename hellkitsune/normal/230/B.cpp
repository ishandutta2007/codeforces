#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool pr[1000001];
vector<LL> all;

int main() {
    REP(i, 1000001) pr[i] = true;
    pr[0] = pr[1] = false;
    for (int i = 2; i < 1234; ++i) if (pr[i]) {
        for (int j = i * i; j < 1000001; j += i) {
            pr[j] = false;
        }
    }
    REP(i, 1000001) if (pr[i]) {
        all.pb((LL)i * i);
    }
    scanf("%d", &n);
    REP(i, n) {
        LL x;
        scanf("%I64d", &x);
        auto it = lower_bound(all.begin(), all.end(), x);
        if (it != all.end() && *it == x) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}