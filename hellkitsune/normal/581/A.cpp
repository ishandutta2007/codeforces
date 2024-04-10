#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    printf("%d %d\n", min(a, b), (max(a, b) - min(a, b)) / 2);
    return 0;
}