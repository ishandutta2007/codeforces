#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int t,x[4],y[4],a[4],b[4],ta[4],tb[4],pa,pb,ans,ax[4],ay[4];
inline void update()
{
    int p[4]={0,1,2,3};
    do
    {
        bool flag=1;
        int maxn=0;
        for(int i=0;i<4;++i)
            if(a[p[i]]!=x[i]&&b[p[i]]!=y[i])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            for(int i=0;i<4;++i)
                maxn=max(maxn,max(abs(a[p[i]]-x[i]),abs(b[p[i]]-y[i])));
            if(maxn<ans)
            {
                ans=maxn;
                for(int i=0;i<4;++i)
                {
                    ax[i]=a[p[i]];
                    ay[i]=b[p[i]];
                }
            }
        }
    }while(next_permutation(p,p+4));
}
inline int calc()
{
    int p[4]={0,1,2,3},res=1e9;
    do
    {
        bool flag=1;
        int maxn=0;
        for(int i=0;i<4;++i)
            if(a[p[i]]!=x[i]&&b[p[i]]!=y[i])
            {
                flag=0;
                break;
            }
        if(flag)
        {
            for(int i=0;i<4;++i)
                maxn=max(maxn,max(abs(a[p[i]]-x[i]),abs(b[p[i]]-y[i])));
            res=min(res,maxn);
        }
    }while(next_permutation(p,p+4));
    return res;
}
int main()
{
    cin>>t;
    while(t--)
    {
        for(int i=0;i<4;++i)
            cin>>x[i]>>y[i];
        ans=1e9;
        for(int s=0;s<1<<4;++s)
        {
            pa=pb=0;
            for(int i=0;i<4;++i)
                if(s>>i&1)
                    ta[pa++]=x[i];
                else
                    tb[pb++]=y[i];
            sort(ta,ta+pa);
            sort(tb,tb+pb);
            pa=unique(ta,ta+pa)-ta;
            pb=unique(tb,tb+pb)-tb;
            if(pa==2&&pb==2)
            {
                if(ta[1]-ta[0]!=tb[1]-tb[0])
                    continue;
                a[0]=a[1]=ta[0];
                a[2]=a[3]=ta[1];
                b[0]=b[2]=tb[0];
                b[1]=b[3]=tb[1];
                update();
            }
            else if(pa==2&&pb==1)
            {
                a[0]=a[1]=ta[0];
                a[2]=a[3]=ta[1];
                b[0]=b[2]=tb[0];
                b[1]=b[3]=tb[0]+ta[1]-ta[0];
                update();
                b[1]=b[3]=tb[0]-ta[1]+ta[0];
                update();
            }
            else if(pa==1&&pb==2)
            {
                b[0]=b[2]=tb[0];
                b[1]=b[3]=tb[1];
                a[0]=a[1]=ta[0];
                a[2]=a[3]=ta[0]+tb[1]-tb[0];
                update();
                a[2]=a[3]=ta[0]-tb[1]+tb[0];
                update();
            }
            else if(pa==2&&pb==0)
            {
                a[0]=a[1]=ta[0];
                a[2]=a[3]=ta[1];
                int l=-2e8,r=2e8,mid1,mid2,w1,w2,val=1e9,node=1e9;
                while(l<=r)
                {
                    mid1=l+(r-l+1)/3;
                    mid2=l+(r-l+1)/3*2;
                    b[0]=b[2]=mid1;
                    b[1]=b[3]=mid1+ta[1]-ta[0];
                    w1=calc();
                    if(w1<val)
                    {
                        val=w1;
                        node=mid1;
                    }
                    b[0]=b[2]=mid2;
                    b[1]=b[3]=mid2+ta[1]-ta[0];
                    w2=calc();
                    if(w2<val)
                    {
                        val=w2;
                        node=mid2;
                    }
                    if(w1<w2)
                        r=mid2-1;
                    else
                        l=mid1+1;
                }
                b[0]=b[2]=l;
                b[1]=b[3]=l+ta[1]-ta[0];
                w1=calc();
                if(w1<val)
                {
                    val=w1;
                    node=mid1;
                }
                b[0]=b[2]=r;
                b[1]=b[3]=r+ta[1]-ta[0];
                w1=calc();
                if(w1<val)
                {
                    val=w1;
                    node=mid1;
                }
                b[0]=b[2]=node;
                b[1]=b[3]=node+ta[1]-ta[0];
                update();
            }
            else if(pa==0&&pb==2)
            {
                b[0]=b[2]=tb[0];
                b[1]=b[3]=tb[1];
                int l=-2e8,r=2e8,mid1,mid2,w1,w2,val=1e9,node=1e9;
                while(l<=r)
                {
                    mid1=l+(r-l+1)/3;
                    mid2=l+(r-l+1)/3*2;
                    a[0]=a[1]=mid1;
                    a[2]=a[3]=mid1+tb[1]-tb[0];
                    w1=calc();
                    if(w1<val)
                    {
                        val=w1;
                        node=mid1;
                    }
                    a[0]=a[1]=mid2;
                    a[2]=a[3]=mid2+tb[1]-tb[0];
                    w2=calc();
                    if(w2<val)
                    {
                        val=w2;
                        node=mid2;
                    }
                    if(w1<w2)
                        r=mid2-1;
                    else
                        l=mid1+1;
                }
                a[0]=a[1]=l;
                a[2]=a[3]=l+tb[1]-tb[0];
                w1=calc();
                if(w1<val)
                {
                    val=w1;
                    node=mid1;
                }
                a[0]=a[1]=r;
                a[2]=a[3]=r+tb[1]-tb[0];
                w1=calc();
                if(w1<val)
                {
                    val=w1;
                    node=mid1;
                }
                a[0]=a[1]=node;
                a[2]=a[3]=node+tb[1]-tb[0];
                update();
            }
        }
        if(ans==1e9)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<ans<<'\n';
        for(int i=0;i<4;++i)
            cout<<ax[i]<<" "<<ay[i]<<'\n';
    }
    return 0;
}