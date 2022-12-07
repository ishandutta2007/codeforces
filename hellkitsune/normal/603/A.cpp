#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[100005];

int main() {
    scanf("%d%s", &n, s);
    int bad = 0;
    REP(i, n - 1) if (s[i] == s[i + 1]) ++bad;
    bad = max(0, bad - 2);
    printf("%d\n", n - bad);
    return 0;
}