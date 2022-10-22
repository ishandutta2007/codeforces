#include <cstdio>
#include <vector>
using namespace std;
int n, t, P[200005];
vector<int> son[200005];
long long ansL[200005], ansR[200005], L[200005], R[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            son[i].clear();
        }
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &P[i]);
            son[P[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &L[i], &R[i]);
        }
        int ans = 0;
        for (int i = n; i >= 1; i--)
        {
            long long sumR = 0;
            for (auto &p : son[i])
            {
                sumR += ansR[p];
            }
            if (sumR >= L[i])
            {
                ansL[i] = L[i];
                ansR[i] = min(sumR, R[i]);
            }
            else
            {
                ans++;
                ansL[i] = L[i];
                ansR[i] = R[i];
            }
        }
        printf("%d\n", ans);
    }
}