#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int n,m,maxn,k;
int f[10000005];
struct gg{
    int num,x;
}s[10000005];
int ans[1000005];
int sum=0;

bool cmp(gg x,gg y)
{
    return x.x<y.x;
}

int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();++f[x];
        maxn=max(maxn,x);
    }
    for(int i=1;i<=m;i++)
    {
        s[i].x=read();s[i].num=i;
    }
    sort(s+1,s+m+1,cmp);
    for(int i=maxn;i;i--)
    {
        if(f[i]>k)
        {
            f[i-1]+=f[i]-k;f[i]=0;
        }
        else
            f[i]=k-f[i];
    }
    if(f[0]>k) return 0*puts("-1");
    else f[0]=k-f[0];
    int j=m;
    for(int i=maxn+1;i<=10000000;i++) f[i]=k;
    for(int i=10000000;i>=0;--i)
    {
        while(j>=1&&s[j].x>=i&&f[i]--)
        {
            ans[++sum]=s[j].num;j--;
        }
    }
    printf("%d\n",sum);
    for(;sum;--sum)printf("%d ",ans[sum]);
    return 0;
}