#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,a[300001],b[300001],ans,maxn[3],minn[3];
inline bool check(int x)
{
    maxn[0]=maxn[1]=maxn[2]=1<<30;
    minn[0]=minn[1]=0;
    minn[2]=-1<<30;
    for(register int i=1;i<=n;++i)
    {
        minn[0]=max(minn[0],a[i]-x);
        maxn[0]=min(maxn[0],a[i]+x);
        minn[1]=max(minn[1],b[i]-x);
        maxn[1]=min(maxn[1],b[i]+x);
        minn[2]=max(minn[2],a[i]-b[i]-x);
        maxn[2]=min(maxn[2],a[i]-b[i]+x);
    }
    if(minn[0]>maxn[0]||minn[1]>maxn[1]||minn[2]>maxn[2]||max(minn[1],minn[0]-maxn[2])>min(maxn[1],maxn[0]-minn[2]))
        return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    {
        string s;
        cin>>s;
        int len=s.length();
        for(register int j=0;j<len;++j)
            if(s[j]=='B')
                ++a[i];
            else
                ++b[i];
    }
    int l=0,r=1e7,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    check(ans);
    printf("%d\n",ans);
    minn[1]=max(minn[1],minn[0]-maxn[2]);
    maxn[1]=min(maxn[1],maxn[0]-minn[2]);
    for(register int i=minn[0];i<=maxn[0];++i)
    {
        int x=max(minn[1],i-maxn[2]),y=min(maxn[1],i-minn[2]);
        if(x>y||(i<=0&&y<=0))
            continue;
        for(register int j=1;j<=i;++j)
            putchar('B');
        for(register int j=1;j<=(i? x:y);++j)
            putchar('N');
        puts("");
        return 0;
    }
    return 0;
}