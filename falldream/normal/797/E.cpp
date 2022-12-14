#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define INF 2000000000
#define MN 100000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}
int num[350][MN+5],n,mx,m,s[MN+5];
int main()
{
    n=read();mx=sqrt(n);
    for(int i=1;i<=n;i++)s[i]=read();m=read();
    for(int i=0;i<=mx;i++)
        for(int j=n;j;--j) num[i][j]=num[i][min(n+1,j+s[j]+i)]+1;
    for(int i=1;i<=m;i++)
    {
        int x=read(),k=read();
        if(k>mx)
        {
            int sum=0;
            for(;x!=n+1;x=min(n+1,x+s[x]+k)) ++sum;
            printf("%d\n",sum);
        }
        else printf("%d\n",num[k][x]);
    }
    return 0;
}