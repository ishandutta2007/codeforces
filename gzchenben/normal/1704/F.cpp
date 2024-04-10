#include <cstdio>
#include <cstring>
using namespace std;
int sg[500005];
bool vis[1005];
void Init_SG()
{
    for (int i = 2; i <= 100; i++)
    {
        memset(vis, false, sizeof(vis));
        for (int j = 0; j <= i - 2; j++)
        {
            vis[sg[j] ^ sg[i - j - 2]] = true;
        }
        for (int j = 0; j <= 100; j++)
        {
            if (!vis[j])
            {
                sg[i] = j;
                break;
            }
        }
    }
    for (int i = 101; i <= 500000; i++)
    {
        sg[i] = sg[i - 34];
    }
}
int n, t;
char a[500005];
int main()
{
    Init_SG();
    scanf("%d", &t);
    while (t--)
    {
        int cntR = 0, cntB = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf(" %c", &a[i]);
            if (a[i] == 'R')
                cntR++;
            else
                cntB++;
        }
        if (cntR != cntB)
        {
            if (cntR > cntB)
                printf("Alice\n");
            else
                printf("Bob\n");
            continue;
        }
        int cur = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cur++;
            if (i == n || a[i] == a[i + 1])
            {
                // printf("%d %d\n", cur, sg[cur]);
                ans ^= sg[cur];
                cur = 0;
            }
        }
        printf(ans == 0 ? "Bob\n" : "Alice\n");
    }
}