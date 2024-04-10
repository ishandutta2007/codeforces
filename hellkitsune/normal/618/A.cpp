#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int v[100005];
int m = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        v[m++] = 1;
        while (m > 1 && v[m - 1] == v[m - 2]) {
            ++v[m - 2];
            --m;
        }
    }
    REP(i, m) printf("%d ", v[i]);
    printf("\n");
    return 0;
}