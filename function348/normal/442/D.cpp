#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
int n;
int ma[N],ma2[N],f[N],fa[N];
int main()
{
    scanf("%d",&n);
    for (int i=2;i<=n+1;i++)
    {
        int x;
        scanf("%d",&x);
        ma[i]=0,ma2[i]=0;f[i]=1;fa[i]=x;
        int y=i;
        if (ma2[x]==0) 
        if (ma[x]!=0) ma2[x]=1;else ma[x]=1;
        while (1)
        {
            if (f[x]==max(ma[x],ma2[x]+1))break;
            if (ma [fa[x]]==f[x]) ma2[fa[x]]=ma[fa[x]],ma[fa[x]]=max(ma[x],ma2[x]+1);else
            if (ma2[fa[x]]==f[x]) ma2[fa[x]]=max(ma[x],ma2[x]+1);
            f[x]=max(ma[x],ma2[x]+1);
            x=fa[x];
        }
        printf("%d%c",ma[1],i<=n?' ':'\n');
    }
    return 0;
}