#include <iostream>

#define ll long long

using namespace std;

bool dp[1<<25],finded[1<<25],D[10][10]={0};
int num[5][5]={0},submask[5][5][5][5]={0};

bool rec(int mask)
{
    if (finded[mask]) return dp[mask];
    if (mask==0) return dp[mask]=false;
    bool loss=false;
    for(int x1=0;x1<5;++x1)
        for(int y1=0;y1<5;++y1)
            for(int x2=x1;x2<5;++x2)
                for(int y2=0;y2<5;++y2)
                    if ((mask&submask[x1][y1][x2][y2])==submask[x1][y1][x2][y2])
                        if (!rec(mask^submask[x1][y1][x2][y2])) return finded[mask]=dp[mask]=true;
    finded[mask]=true;
    return dp[mask]=loss;
}

int main()
{
    char c;
    int cmask=0;
    memset(finded,false,sizeof(dp));
    for(int i=0;i<5;i++)
        for(int j=max(0,i-2);j<3+i&&j<5;j++)
        {
            cin >> c;
            if (c=='O') D[i][j]=true,cmask|=(1<<(5*i+j));
        }
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            num[i][j]=1<<(5*i+j);
    for(int x1=0;x1<5;++x1)
        for(int y1=0;y1<5;++y1)
            for(int x2=x1;x2<5;++x2)
                for(int y2=0;y2<5;++y2)
                {
                    submask[x1][y1][x2][y2]=(1<<27)-1;
                    if (x1==x2)
                    {
                        int cmask=0,y=max(y1,y2);
                        for(int i=min(y1,y2);i<=y;i++)
                            cmask|=num[x1][i];
                        submask[x1][y1][x2][y2]=cmask;
                    }
                    else
                        if (y1==y2)
                        {
                            int cmask=0,x=max(x1,x2);
                            for(int i=min(x1,x2);i<=x;i++)
                                cmask|=num[i][y1];
                            submask[x1][y1][x2][y2]=cmask;
                        }
                        else
                            if (x1-x2==y1-y2)
                            {
                                int cmask=0,x=min(x1,x2),y=min(y1,y2),Y=max(y1,y2);
                                for(int i=min(y1,y2);i<=Y;i++)
                                    cmask|=(num[(x+i-y)][i]);
                                submask[x1][y1][x2][y2]=cmask;
                            }
                }
    if (rec(cmask)) cout << "Karlsson\n";
    else cout << "Lillebror\n";
    return 0;
}