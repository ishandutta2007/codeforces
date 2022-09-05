#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
int n,m,a[111][111],b[111][111];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t<n)t=t*2;
        if(t==n)
        {
            int tn=i;
            for(int tx=1;tx<=i;tx++)for(int ty=1;ty<=m;ty++)b[tx][ty]=a[tx][ty];
            while(tn<n)
            {
                for(int tx=1;tx<=tn;tx++)
                {
                    for(int ty=1;ty<=m;ty++)
                    {
                        b[tn*2-tx+1][ty]=b[tx][ty];
                    }
                }
                tn=tn*2;
            }
            bool ok=1;
            for(int tx=1;tx<=n;tx++)for(int ty=1;ty<=m;ty++)if(a[tx][ty]!=b[tx][ty]){ok=0;break;}
            if(ok)
            {
                printf("%d",i);
            //system("pause");
                return 0;
            }
        }
    }
    return 0;
}