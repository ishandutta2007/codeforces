#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<set>
#include<cmath>
#define MN 10005
#define INF 200000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}


int n,s[MN+5],m,ans=INF,k;

int abs(int x){return  x<0?-x:x;}

int main()
{
    n=read();k=read();m=read();
    for(int i=1;i<=n;i++)s[i]=read();
    for(int i=1;i<=n;i++)if(s[i]&&s[i]<=m)
        ans=min(ans,abs(k-i));
    printf("%d\n",ans*10);
    return 0;
}