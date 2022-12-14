#include<bits/stdc++.h>
#define MN 1000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,fa[MN+5],mx[MN+5],from[MN+5],mx2[MN+5],f[MN+5];
int main()
{
    n=read()+1;
    for(int i=2;i<=n;++i)
    {
        fa[i]=read();mx[i]=0;mx2[i]=0;f[i]=1;
        for(int j=fa[i],k=i;j;k=j,j=fa[j])
        {
            int pre=f[j];
            if(k==from[j]) mx[j]=f[k];
            else if(f[k]>mx[j]) mx2[j]=mx[j],mx[j]=f[k],from[j]=k;
            else if(f[k]>mx2[j]) mx2[j]=f[k];
            f[j]=max(mx[j],mx2[j]+(j>1));
            if(f[j]==pre) break;
        }
        printf("%d ",f[1]);
    }
    return 0;
}