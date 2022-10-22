#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, t, a[200005];
int MaxA[200005][20];
long long sum[200005];
long long MinS[200005][20], MaxS[200005][20];
int maxA(int x, int y) { return a[x] > a[y] ? x : y; }

int FindMaxA(int L, int R)
{
    int tmp = log2(R - L + 1);
    return maxA(MaxA[L][tmp], MaxA[R - (1 << tmp) + 1][tmp]);
}
long long FindMinS(int L, int R)
{
    int tmp = log2(R - L + 1);
    return min(MinS[L][tmp], MinS[R - (1 << tmp) + 1][tmp]);
}
long long FindMaxS(int L, int R)
{
    int tmp = log2(R - L + 1);
    return max(MaxS[L][tmp], MaxS[R - (1 << tmp) + 1][tmp]);
}
bool Check(int L, int R)
{
    // printf("checking %d %d\n", L, R);
    if (L >= R)
        return true;
    int Maxn = FindMaxA(L, R);
    if (FindMinS(L - 1, Maxn - 1) < sum[Maxn - 1])
    {
        // printf("FindMinS(%d,%d) < sum[%d]\n", L - 1, Maxn - 1, Maxn - 1);
        return false;
    }
    if (FindMaxS(Maxn, R) > sum[Maxn])
    {
        // printf("FindMaxS(%d,%d) > sum[%d]\n", Maxn, R, Maxn);
        return false;
    }
    if (!Check(L, Maxn - 1))
        return false;
    if (!Check(Maxn + 1, R))
        return false;
    return true;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            MaxA[i][0] = i;
            MinS[i][0] = MaxS[i][0] = sum[i];
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j < 20; j++)
            {
                if (i + (1 << j) > n + 1)
                    continue;
                MaxA[i][j] = maxA(MaxA[i][j - 1], MaxA[i + (1 << (j - 1))][j - 1]);
            }
        }
        for (int i = n; i >= 0; i--)
        {
            for (int j = 1; j < 20; j++)
            {
                if (i + (1 << j) > n + 1)
                    continue;
                MaxS[i][j] = max(MaxS[i][j - 1], MaxS[i + (1 << (j - 1))][j - 1]);
                MinS[i][j] = min(MinS[i][j - 1], MinS[i + (1 << (j - 1))][j - 1]);
            }
        }
        printf(Check(1, n) ? "YES\n" : "NO\n");
    }
}