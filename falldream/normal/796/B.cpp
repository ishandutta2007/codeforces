#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<cmath>
#define MN 1000005
#define INF 200000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,m,k,pos=1;
bool b[MN+5];

int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=m;i++)b[read()]=1;
    if(b[1])return 0*puts("1");
    for(int i=1;i<=k;i++)
    {
        int u=read(),v=read();
        if(u==pos)
        {
            pos=v;if(b[v])return 0*printf("%d\n",v);
        }
        else if(v==pos)
        {
            pos=u;if(b[u])return 0*printf("%d\n",u);
        }
    }
    printf("%d\n",pos);
    return 0;
}