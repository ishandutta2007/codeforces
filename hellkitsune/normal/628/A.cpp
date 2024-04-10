#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, b, p;

int main() {
    scanf("%d%d%d", &n, &b, &p);
    int nn = n;
    int bb = 0;
    while (n > 1) {
        int cnt = 1;
        while (2 * cnt <= n) cnt <<= 1;
        bb += b * cnt + cnt / 2;
        n -= cnt / 2;
    }
    cout << bb << ' ' << nn * p << endl;
    return 0;
}