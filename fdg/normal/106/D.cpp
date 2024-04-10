#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <cmath>

using namespace std;

char F[1001][1001];
int up[1001][1001],Left[1001][1001],Right[1001][1001],down[1001][1001];
int n,m;
char dir[100001];
int len[100001];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++)
        gets(F[i]);
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
        {
            up[i][j]=(F[i][j]!='#');
            if (up[i][j]>0) up[i][j]+=up[i-1][j];
        }
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<m-1;j++)
        {
            down[i][j]=(F[i][j]!='#');
            if (down[i][j]>0) down[i][j]+=down[i+1][j];
        }
    for(int j=1;j<m-1;j++)
        for(int i=1;i<n-1;i++)
        {
            Left[i][j]=(F[i][j]!='#');
            if (Left[i][j]>0) Left[i][j]+=Left[i][j-1];
        }
    for(int j=m-1;j>=1;j--)
        for(int i=1;i<n-1;i++)
        {
            Right[i][j]=(F[i][j]!='#');
            if (Right[i][j]>0) Right[i][j]+=Right[i][j+1];
        }
    int x[27]={0},y[27]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if (F[i][j]>='A'&&F[i][j]<='Z') x[F[i][j]-'A']=i,y[F[i][j]-'A']=j;
    string ans;
    int k;
    scanf("%d\n",&k);
    for(int i=0;i<k;i++)
        scanf("%c %d\n",&dir[i],&len[i]);
    for(int t=0;t<26;t++)
    {
        bool ok=true;
        if (x[t]==0&&y[t]==0) continue;
        int curx=x[t],cury=y[t];
        for(int i=0;i<k;i++)
        {
            if (dir[i]=='N')
                if (up[curx][cury]>len[i]) curx-=len[i];
                else
                {
                    ok=false;
                    break;
                }
            if (dir[i]=='S')
                if (down[curx][cury]>len[i]) curx+=len[i];
                else
                {
                    ok=false;
                    break;
                }
            if (dir[i]=='E')
                if (Right[curx][cury]>len[i]) cury+=len[i];
                else
                {
                    ok=false;
                    break;
                }
            if (dir[i]=='W')
                if (Left[curx][cury]>len[i]) cury-=len[i];
                else
                {
                    ok=false;
                    break;
                }
        }
        if (ok) ans+=(char)('A'+t);
    }
    if (ans.size()==0) printf("no solution\n");
    else cout << ans << endl;
    return 0;
}