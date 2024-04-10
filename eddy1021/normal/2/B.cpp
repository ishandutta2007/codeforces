#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int n, in[MAXN][MAXN], cnt2[MAXN][MAXN], cnt5[MAXN][MAXN];

typedef pair<int, int> pii;

pii dp[2][MAXN][MAXN];
int prv[2][MAXN][MAXN];

void print(int k, int i, int j)
{
    if(i == 1 && j == 1) return ;
    if(prv[k][i][j] < 2)
    {
        print(prv[k][i][j], i-1, j);
        printf("D");
    }
    else
    {
        print(prv[k][i][j]-2, i, j-1);
        printf("R");
    }
}

inline int get(pii p)
{return min(p.first, p.second);}

void shit(int x, int y)
{
    printf("1\n");
    for(int i = 1; i < x; i++) printf("D");
    for(int i = 1; i < y; i++) printf("R");
    for(int i = x; i < n; i++) printf("D");
    for(int i = y; i < n; i++) printf("R");
}

int main()
{
    bool flag = 0;
    int x0, y0;
    scanf("%d", &n);
    auto loop = [&](int i){for(int j = 1; j <= n; scanf("%d", &in[i][j]), j++);};
    for(int i = 1; i <= n; [&](int i){for(int j = 1; j <= n; scanf("%d", &in[i][j]), j++);}(i), i++);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(in[i][j] == 0)
            {
                flag = 1;
                in[i][j] = 10;
                x0 = i, y0 = j;
            }
            int tmp = in[i][j];
            while(tmp%2==0 && tmp > 0)
            {
                tmp/=2;
                cnt2[i][j]++;
            }
            while(tmp%5==0 && tmp > 0)
            {
                tmp/=5;
                cnt5[i][j]++;
            }
        }
    for(int i = 0; i <= n; i++)
    {
        fill(dp[0][i], dp[0][i]+n+1, pii(1000000, 1000000));
        fill(dp[1][i], dp[1][i]+n+1, pii(1000000, 1000000));
    }
    dp[0][0][1] = dp[1][0][1] = pii(0, 0);
    dp[1][1][0] = dp[0][1][0] = pii(0, 0);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
    {
        int c2 = cnt2[i][j], c5 = cnt5[i][j];
        pii upd[4];
        upd[0] = pii(dp[0][i-1][j].first+c2, dp[0][i-1][j].second+c5);
        upd[1] = pii(dp[1][i-1][j].first+c2, dp[1][i-1][j].second+c5);
        upd[2] = pii(dp[0][i][j-1].first+c2, dp[0][i][j-1].second+c5);
        upd[3] = pii(dp[1][i][j-1].first+c2, dp[1][i][j-1].second+c5);

        int id2 = 0, id5 = 0;

        for(int k = 0; k < 4; k++)
            if(upd[k].first < upd[id2].first) id2 = k;
            else if(upd[k].first == upd[id2].first &&
                    upd[k].second < upd[id2].second)
                id2 = k;
        for(int k = 0; k < 4; k++)
            if(upd[k].second < upd[id5].second) id5 = k;
            else if(upd[k].second == upd[id2].second &&
                    upd[k].first < upd[id2].first)
                id5 = k;
        dp[0][i][j] = upd[id2];prv[0][i][j] = id2;
        dp[1][i][j] = upd[id5];prv[1][i][j] = id5;
    }
    if(get(dp[0][n][n]) < get(dp[1][n][n]))
    {
        if(flag && get(dp[0][n][n]) > 1)
            shit(x0, y0);
        else
        {
            printf("%d\n", get(dp[0][n][n]));
            print(0, n, n);
        }
    }
    else
    {
        if(flag && get(dp[1][n][n]) > 1)
            shit(x0, y0);
        else
        {
            printf("%d\n", get(dp[1][n][n]));
            print(1, n, n);
        }
    }
    puts("");
}