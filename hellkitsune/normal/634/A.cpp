#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> a, b;

int main() {
    scanf("%d", &n);
    a.resize(n);
    b.resize(n);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, n) if (a[i] == 0) {
        a.erase(a.begin() + i, a.begin() + i + 1);
    }
    REP(i, n) if (b[i] == 0) {
        b.erase(b.begin() + i, b.begin() + i + 1);
    }
    --n;
    REP(i, n) if (b[i] == a[0]) {
        REP(j, n) if (b[(i + j) % n] != a[j]) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        break;
    }
    return 0;
}