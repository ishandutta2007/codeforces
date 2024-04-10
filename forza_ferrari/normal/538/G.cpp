#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
const char ch[]={'L','D','U','R'};
struct element
{
    int x,y,p,q;
    bool operator <(element &other) const
    {
        return q<other.q;
    }
}a[200005];
int n,m,ans[2000001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||x>'9')
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
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        int t=read(),x=read(),y=read();
        if((x+y+t)&1)
        {
            cout<<"NO\n";
            return 0;
        }
        a[i].x=(x+y+t)>>1;
        a[i].y=(x-y+t)>>1;
        a[i].p=t/m;
        a[i].q=t%m;
    }
    a[++n]={0,0,0,0};
    a[++n]={0,0,-1,m};
    sort(a+1,a+n+1);
    int l=0,r=m;
    for(int i=1;i<n;++i)
    {
        if(a[i+1].p==a[i].p)
        {
            if(a[i+1].x-a[i].x-a[i+1].q+a[i].q>0||a[i+1].x-a[i].x<0)
            {
                cout<<"NO\n";
                return 0;
            }
        }
        else if(a[i+1].p>a[i].p)
        {
            l=max(l,(int)ceil(1.0l*(a[i+1].x-a[i].x-a[i+1].q+a[i].q)/(a[i+1].p-a[i].p)));
            r=min(r,(int)floor(1.0l*(a[i+1].x-a[i].x)/(a[i+1].p-a[i].p)));
        }
        else
        {
            l=max(l,(int)ceil(1.0l*(a[i+1].x-a[i].x)/(a[i+1].p-a[i].p)));
            r=min(r,(int)floor(1.0l*(a[i+1].x-a[i].x-a[i+1].q+a[i].q)/(a[i+1].p-a[i].p)));
        }
    }
    if(l>r)
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        int val=a[i+1].x-a[i].x-(a[i+1].p-a[i].p)*l;
        for(int j=a[i].q+1;j<=a[i].q+val;++j)
            ans[j]|=2;
    }
    l=0,r=m;
    for(int i=1;i<n;++i)
    {
        if(a[i+1].p==a[i].p)
        {
            if(a[i+1].y-a[i].y-a[i+1].q+a[i].q>0||a[i+1].y-a[i].y<0)
            {
                cout<<"NO\n";
                return 0;
            }
        }
        else if(a[i+1].p>a[i].p)
        {
            l=max(l,(int)ceil(1.0l*(a[i+1].y-a[i].y-a[i+1].q+a[i].q)/(a[i+1].p-a[i].p)));
            r=min(r,(int)floor(1.0l*(a[i+1].y-a[i].y)/(a[i+1].p-a[i].p)));
        }
        else
        {
            l=max(l,(int)ceil(1.0l*(a[i+1].y-a[i].y)/(a[i+1].p-a[i].p)));
            r=min(r,(int)floor(1.0l*(a[i+1].y-a[i].y-a[i+1].q+a[i].q)/(a[i+1].p-a[i].p)));
        }
    }
    if(l>r)
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        int val=a[i+1].y-a[i].y-(a[i+1].p-a[i].p)*l;
        for(int j=a[i].q+1;j<=a[i].q+val;++j)
            ans[j]|=1;
    }
    for(int i=1;i<=m;++i)
        putchar(ch[ans[i]]);
    return 0;
}