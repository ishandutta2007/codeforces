#include <bits/stdc++.h>

using namespace std;

int N;
char buf[3];
bool has[5][5];
bool tmp[5][5];

bool get(int row, int mask)
{
    int ret=0;
    int tot=0;
    for(int i=0; i<5; i++)
    {
        ret+=(mask&(1<<i)) && has[row][i];
        tot+=has[row][i];
    }
    return ret>=tot-1;
}

bool get2(int col, int mask)
{
    int ret=0;
    int tot=0;
    for(int i=0; i<5; i++)
    {
        ret+=(mask&(1<<i)) && has[i][col];
        tot+=has[i][col];
    }
    return ret>=tot-1;
}

int solve()
{
    int ret=0x3f3f3f3f;
    for(int row=0; row<(1<<5); row++)
        for(int col=0; col<(1<<5); col++)
        {
            memcpy(tmp, has, sizeof tmp);
            for(int i=0; i<5; i++)
                if(col&(1<<i))
                    for(int j=0; j<5; j++)
                        tmp[i][j]=false;
            for(int j=0; j<5; j++)
                if(row&(1<<j))
                    for(int i=0; i<5; i++)
                        tmp[i][j]=false;
            int tot=0;
            for(int i=0; i<5; i++)
                for(int j=0; j<5; j++)
                    tot+=tmp[i][j];
            if(tot<=1)
            {
                for(int i=0; i<5; i++)
                    if(!get(i, row) || !get2(i, col))
                        goto next;
                ret=min(ret, __builtin_popcount(row)+__builtin_popcount(col));
            }
            next:;
        }
    return ret;
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%s", buf);
        switch(buf[0])
        {
        case 'R': a=0; break;
        case 'G': a=1; break;
        case 'B': a=2; break;
        case 'Y': a=3; break;
        case 'W': a=4; break;
        }
        b=buf[1]-'1';
        has[a][b]=true;
    }
    printf("%d\n", solve());
    return 0;
}