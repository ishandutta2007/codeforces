#include<iostream>
#include<fstream>
using namespace std;
const int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1};
int i,j,k,n,m,cnt;
char c;
int a[1234][1234];
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("\n");
        for(j=1;j<=m;j++)
        {
            scanf("%c",&c);
            if(c=='.')a[i][j]=0;
            else if(c=='*')a[i][j]=9;
            else a[i][j]=c-48;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]>=0&&a[i][j]<=8)
            {
                cnt=0;
                for(k=0;k<8;k++)
                {
                    if(a[i+dx[k]][j+dy[k]]==9)cnt++;
                }
                if(cnt!=a[i][j])
                {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    return 0;
}