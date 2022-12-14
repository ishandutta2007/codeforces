#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,q,res[MN+5][MN+5],top=0;
pair<int,int> a[MN*MN+5];
int main()
{
    n=read();m=read();q=read();
    for(int i=1,ii;i<=q;++i)
        if((ii=read())==3)
        {
            int x=read(),y=read(),v=read();
            for(int j=top;j;--j)
                if(a[j].first==1){if(a[j].second==x) y=y%m+1;}
                else if(a[j].second==y) x=x%n+1;
            res[x][y]=v;
        }
        else a[++top]=make_pair(ii,read());
    for(int i=1;i<=n;++i,puts(""))
        for(int j=1;j<=m;++j)
            printf("%d ",res[i][j]);
    return 0;
}