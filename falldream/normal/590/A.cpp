#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 500000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int mx,a[MN+5],res[MN+5],n;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();a[n+1]=a[n];
    res[1]=a[1];res[n]=a[n];
    for(int i=2,j=0;i<=n+1;++i)
        if(a[i]==a[i-1])
        {
            res[i]=a[i];
            if(j)
            {
                mx=max(mx,(i-j-1)>>1);
                if((i-j)&1) for(int k=j;k<i;++k) res[k]=a[i-1];
                else
                {
                    int len=(i-j)>>1;
                    for(int k=0;k<len;++k) res[j+k]=a[j],res[j+len+k]=a[i-1];
                }
                j=0;
            }
        }
        else if(!j) j=i-1;
    printf("%d\n",mx);
    for(int i=1;i<=n;++i) printf("%d ",res[i]);
    return 0;
}