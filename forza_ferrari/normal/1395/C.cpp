#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[201],b[201],num[201][201],ans,maxn;
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
    }
    for(register int i=1;i<=m;++i)
    {
        scanf("%d",&b[i]);
        maxn=max(maxn,b[i]);
        for(register int j=1;j<=n;++j)
            num[j][i]=a[j]&b[i];
    }
    for(register int i=10;i>=0;--i)
    {
        if((1<<i)>maxn)
            continue;
        bool flag=1;
        for(register int j=1;j<=n;++j)
        {
            bool tag=0;
            for(register int k=1;k<=m;++k)
                if(num[j][k]!=-1&&!((num[j][k]>>i)&1))
                {
                    tag=1;
                    break;
                }
            if(!tag)
            {
                flag=0;
                break;
            }
        }
        if(!flag)
            ans+=1<<i;
        else
            for(register int j=1;j<=n;++j)
                for(register int k=1;k<=m;++k)
                    if((num[j][k]>>i)&1)
                        num[j][k]=-1;
    }
    printf("%d\n",ans);
    return 0;
}