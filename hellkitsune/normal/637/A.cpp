#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int cnt[1000001] = {};
int best = 0, bestInd = -1;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        if (++cnt[x] > best) {
            best = cnt[x];
            bestInd = x;
        }
    }
    printf("%d\n", bestInd);
    return 0;
}