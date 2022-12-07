#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000], b[1000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    int x = 0, y = 0;
    REP(i, n) x |= a[i];
    REP(i, n) y |= b[i];
    cout << (LL)x + y << endl;
    return 0;
}