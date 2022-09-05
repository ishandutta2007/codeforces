#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, K;

long long F (int x)
{
    return 1LL * (N / (x + 1)) * (M / (K - x + 1));
}

long long ternar_search (int left, int right)
{
    if (left == right)
        return F (left);

    if (right == left + 1)
        return max (F (left), F (right));

    int mid1, mid2;
    long long c1, c2;

    mid1 = left + (right - left) / 3;
    mid2 = right - (right - left) / 3;

    c1 = F (mid1), c2 = F (mid2);

    if (c1 > c2)
        return max (F(right), max (F(left), ternar_search (left, mid2 - 1)));
    return max (F(right), max (F(left), ternar_search (mid1 + 1, right)));
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);

if (max (K - M + 1, 0) > min (N - 1, K))
{
    printf ("-1\n");
    return 0;
}

printf ("%I64d\n", ternar_search (max (K - M + 1, 0), min (N - 1, K)));

return 0;
}