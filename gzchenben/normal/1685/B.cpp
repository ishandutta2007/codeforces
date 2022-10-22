#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, t, A, B, C, D, s[200005], cntA, cntB;
char ch[200005];
vector<int> vecA, vecB;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        scanf("%s", ch + 1);
        n = strlen(ch + 1);
        cntA = cntB = 0;
        for (int i = 1; i <= n; i++)
        {
            s[i] = (ch[i] == 'A' ? 0 : 1);
            cntA += (1 - s[i]);
            cntB += s[i];
        }
        if (cntA != A + C + D || cntB != B + C + D)
        {
            printf("NO\n");
            continue;
        }
        int tot = 0, Now = 0;
        vecA.clear();
        vecB.clear();
        for (int i = 1; i <= n; i++)
        {
            Now++;
            if (s[i] != s[i + 1] && i != n)
                continue;
            if (Now % 2 == 1)
            {
                tot += Now / 2;
            }
            else
            {
                tot += Now / 2 - 1;
                if (s[i] == 0)
                    vecB.push_back(Now / 2);
                if (s[i] == 1)
                    vecA.push_back(Now / 2);
            }
            Now = 0;
        }
        int resA = C, resB = D;
        sort(vecA.begin(), vecA.end());
        sort(vecB.begin(), vecB.end());
        for (auto &p : vecA)
        {
            // printf("? A %d\n", p);
            if (resA < p)
                break;
            resA -= p;
            tot++;
        }
        for (auto &p : vecB)
        {
            // printf("? B %d\n", p);
            if (resB < p)
                break;
            resB -= p;
            tot++;
        }
        if (tot >= C + D)
            printf("YES\n");
        else
            printf("NO\n");
    }
}