#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int t,n,a[100001][4],ans[4];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline bool check(int len)
{
    int l[4]={(int)-8e18,(int)-8e18,(int)-8e18,(int)-8e18},r[4]={(int)8e18,(int)8e18,(int)8e18,(int)8e18},tl[4],tr[4];
    for(int i=1;i<=n;++i)
        for(int j=0;j<4;++j)
        {
            l[j]=max(l[j],a[i][j]-len);
            r[j]=min(r[j],a[i][j]+len);
        }
    for(int i=0;i<4;++i)
        if(l[i]>r[i])
            return 0;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<4;++j)
        {
            tl[j]=l[j]-(j? 1:3)*i;
            tr[j]=r[j]-(j? 1:3)*i;
            tl[j]=(tl[j]+(tl[j]>=0))/2;
            tr[j]=(tr[j]-(tr[j]<0))/2;
        }
        if(tl[0]<=tr[0]&&tl[1]<=tr[1]&&tl[2]<=tr[2]&&tl[3]<=tr[3]&&tl[1]+tl[2]+tl[3]<=tr[0]&&tr[1]+tr[2]+tr[3]>=tl[0])
        {
            ans[1]=tl[1];
            ans[2]=tl[2];
            ans[3]=tl[3];
            int w=tl[0]-ans[1]-ans[2]-ans[3];
            if(w<0)
                w=0;
            ans[1]+=min(w,tr[1]-tl[1]);
            w-=min(w,tr[1]-tl[1]);
            ans[2]+=min(w,tr[2]-tl[2]);
            w-=min(w,tr[2]-tl[2]);
            ans[3]+=min(w,tr[3]-tl[3]);
            w-=min(w,tr[3]-tl[3]);
            ans[1]=2*ans[1]+i;
            ans[2]=2*ans[2]+i;
            ans[3]=2*ans[3]+i;
            ans[0]=ans[1]+ans[2]+ans[3];
            return 1;
        }
    }
    return 0;
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            int x=read(),y=read(),z=read();
            a[i][0]=x+y+z;
            a[i][1]=-x+y+z;
            a[i][2]=x-y+z;
            a[i][3]=x+y-z;
        }
        check(0);
        int l=0,r=4e18,mid,res;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid))
            {
                res=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(!check(res))
            return -1;
        int x=(ans[0]-ans[1])/2,y=(ans[0]-ans[2])/2,z=(ans[0]-ans[3])/2;
        if(x<0)
        {
            putchar('-');
            x=-x;
        }
        print(x);
        putchar(' ');
        if(y<0)
        {
            putchar('-');
            y=-y;
        }
        print(y);
        putchar(' ');
        if(z<0)
        {
            putchar('-');
            z=-z;
        }
        print(z);
        putchar('\n');
    }
    return 0;
}