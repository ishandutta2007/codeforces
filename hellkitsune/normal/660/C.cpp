#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[300000];
queue<int> q;
int best = -1, s = -1, t = -1;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    int from = 0;
    REP(i, n) {
        if (a[i] == 0) q.push(i);
        if ((int)q.size() > k) {
            from = (int)q.front() + 1;
            q.pop();
        }
        if (i - from + 1 > best) {
            best = i - from + 1;
            s = from;
            t = i;
        }
    }
    for (int i = s; i <= t; ++i) {
        a[i] = 1;
    }
    printf("%d\n", best);
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}