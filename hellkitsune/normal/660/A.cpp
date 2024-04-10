#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];
vector<int> b;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int tot = 0;
    REP(i, n) {
        b.pb(a[i]);
        if (i < n - 1 && gcd(a[i], a[i + 1]) != 1) {
            b.pb(1);
            ++tot;
        }
    }
    printf("%d\n", tot);
    for (int x : b) printf("%d ", x);
    printf("\n");
    return 0;
}