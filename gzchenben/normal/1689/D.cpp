#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t, PreAns[1005], SufAns[1005], H[1005];
char ch[1005][1005];
vector<pair<int, int>> Points;
pair<int, int> AnsPos;
int AnsVal;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        Points.clear();
        AnsVal = 1e9;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int Fir = 0, Lst = 0;
            for (int j = 1; j <= m; j++)
            {
                scanf(" %c", &ch[i][j]);
                if (!Fir && ch[i][j] == 'B')
                    Fir = j;
                if (ch[i][j] == 'B')
                    Lst = j;
            }
            if (Fir)
                Points.push_back({i, Fir});
            if (Lst != Fir)
                Points.push_back({i, Lst});
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                H[j] = -1;
            for (auto &p : Points)
            {
                H[p.second] = max(H[p.second], abs(p.first - i));
                // printf("i = %d H[%d] = %d\n", i, p.second, H[p.second]);
            }
            PreAns[0] = SufAns[m + 1] = -1;
            for (int j = 1; j <= m; j++)
            {
                PreAns[j] = (PreAns[j - 1] != -1 ? PreAns[j - 1] + 1 : -1);
                PreAns[j] = max(PreAns[j], H[j]);
            }
            for (int j = m; j >= 1; j--)
            {
                SufAns[j] = (SufAns[j + 1] != -1 ? SufAns[j + 1] + 1 : -1);
                SufAns[j] = max(SufAns[j], H[j]);
            }
            for (int j = 1; j <= m; j++)
            {
                // printf("ans(%d,%d) : %d\n", i, j, max(SufAns[j], PreAns[j]));
                if (max(SufAns[j], PreAns[j]) < AnsVal)
                {
                    AnsVal = max(SufAns[j], PreAns[j]);
                    AnsPos = {i, j};
                }
            }
        }
        printf("%d %d\n", AnsPos.first, AnsPos.second);
    }
}