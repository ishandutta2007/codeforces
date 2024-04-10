#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 1000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool flag[MN+5];
int n,m,c,a[MN+5],exp[MN+5];
void Set(int i,int x){flag[i]=1;a[i]=x;printf("%d\n",i);fflush(stdout);}
int main()
{
    n=read();m=read();c=read();
    for(int i=1;i<=n;++i)
    {
        exp[i]=int((double)c/n*i);
        exp[i]=max(exp[i],1);
        exp[i]=min(exp[i],c);
    }
    int mid=(1+n)>>1,midc=(1+c)>>1;
    for(int i=1;i<=m;++i)
    {
        int x=read(),f=0;
        if(x>midc)
        {
            for(int j=n;j>mid;--j)
                if(!flag[j] || x>a[j]) {Set(j,x);f=1;break;}
            if(!f)
            {
                for(int j=mid;j;--j) if(!flag[j] || x>a[j]) {Set(j,x);f=1;break;}
                if(!f) Set(1,x);
            }
        }
        else
        {
            for(int j=1;j<=mid;++j) if(!flag[j] || x<a[j]) {Set(j,x);f=1;break;}
            if(!f)
            {
                for(int j=mid+1;j<=n;++j) if(!flag[j] || x<a[j]) {Set(j,x);f=1;break;}
                if(!f) Set(n,x);
            }
        }
        int ok=1;
        for(int i=1;i<=n;++i) if(!flag[i]||(i>1&&a[i-1]>a[i])) ok=0;
        if(ok) return 0;
    }
    return 0;
}