#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int main()
{
    int l, p, q;
    scanf("%d%d%d", &l, &p, &q);
    printf("%.12f\n", (double)l * p / (p + q));
    return 0;
}