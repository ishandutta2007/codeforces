#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, a;
int pre[101];

int solve(int x) {
    if (x <= 100) return pre[x];
    if (x & 1) return 0;
    int mex = 0;
    int a = solve(x - 1);
    int b = solve(x >> 1);
    if (a == 0 || b == 0) {
        mex = 1;
        if (a == 1 || b == 1) {
            mex = 2;
        }
    }
    return mex;
}

int main() {
    pre[0] = 0;
    for (int i = 1; i <= 100; ++i) {
        int &mex = pre[i];
        if (pre[i - 1] == 0 || (i % 2 == 0 && pre[i / 2] == 0)) {
            mex = 1;
            if (pre[i - 1] == 1 || (i % 2 == 0 && pre[i / 2] == 1)) {
                mex = 2;
            }
        }
    }
    scanf("%d%d", &n, &k);
    int ans = 0;
    if (k % 2 == 0) {
        REP(i, n) {
            scanf("%d", &a);
            if (a < 3) ans ^= a;
            else ans ^= (a & 1) ^ 1;
        }
    } else {
        REP(i, n) {
            scanf("%d", &a);
            ans ^= solve(a);
        }
    }
    if (ans) printf("Kevin\n");
    else printf("Nicky\n");
    return 0;
}