#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 100
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,k,m,a,num[MN+5],last[MN+5],rk[MN+5],d[MN+5];
bool cmp(int x,int y){return num[x]==num[y]?last[x]<last[y]:num[x]>num[y];}
int Check(int x)
{
    for(int i=1;i<=n;++i) rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    for(int i=1;i<=n;++i) if(rk[i]==x) return num[x]&&i<=k;
}

int main()
{
    n=read();k=read();m=read();a=read();
    if(n==1) return 0*puts("1");
    for(int i=1,j;i<=a;++i) ++num[j=read()],last[j]=i;
    for(int i=1;i<=n;++i)
    {
        int pn=num[i],pl=last[i];
        num[i]+=m-a;if(m!=a) last[i]=m;
        if(!Check(i)){printf("3 ");num[i]=pn;last[i]=pl;continue;}
        num[i]=pn;last[i]=pl;
        if(!num[i]) {printf("2 ");continue;}
        if(k==n) {printf("1 ");continue;}
        for(int j=1;j<=n;++j) if(i!=j)
        {
            if(num[j]>num[i]) d[j]=0;
            else if(num[j]==num[i]) d[j]=last[j]>last[i];
            else d[j]=max(0,num[i]+1-num[j]);
        }
        else d[j]=1e9;
        int tot=0;sort(d+1,d+n+1);
        for(int i=1;i<=k;++i) tot+=d[i];
        if(tot<=m-a) printf("2 ");
        else printf("1 ");
    }
    return 0;
}