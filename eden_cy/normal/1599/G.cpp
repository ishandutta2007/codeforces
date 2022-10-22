#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

struct P{
    int x,y,id;
}p[N];

P operator -(P a,P b)
{
    return {a.x-b.x,a.y-b.y};
}

int operator *(P a,P b)
{
    return a.x*b.y-a.y*b.x;
}

int dot(P a,P b)
{
    return a.x*b.x+a.y*b.y;
}

double dis(P a)
{
    return sqrt(dot(a,a));
}

int n,k;

bool cmp(const P &a,const P &b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

bool online(P a,P b,P c)
{
    return (c-a)*(b-a)==0;
}

vector<P>v;

P out;

signed main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y),p[i].id=i;
    sort(p+1,p+n+1,cmp);
    int cnt=0,pos=-1;
    for(int j=3;j<=n;j++)
    {
        if(!online(p[1],p[2],p[j]))
            pos=j,cnt++;
    }
    if(cnt!=1)
    {
        //not one is 1 or 2
        cnt=2;
        for(int j=4;j<=n;j++)
            cnt+=online(p[2],p[3],p[j]);
        if(cnt==n-1)
            pos=1;
        else
            pos=2;
    }
    //pos is the outer point
    for(int i=1;i<=n;i++)
        if(i!=pos)
            v.push_back(p[i]);
    double ans=1e18;
    out=p[pos];
    if(k==out.id)
    {
        ans=min(ans,dis(v[0]-p[pos])+dis(v[0]-v.back()));
        ans=min(ans,dis(v.back()-p[pos])+dis(v[0]-v.back()));
        printf("%.10lf\n",ans);
        return 0;
    }
    if(v[0].id==k||v.back().id==k)
    {
        if(v.back().id==k)
            reverse(v.begin(),v.end());
        ans=min(ans,dis(v[0]-out)+dis(out-v[1])+dis(v[1]-v.back()));
        ans=min(ans,dis(v[0]-out)+dis(out-v.back())+dis(v.back()-v[1]));
        ans=min(ans,dis(v[0]-v.back())+dis(v.back()-out));
        int pk=0;
        for(int i=0;i<v.size();i++)
        {
            double td=dis(v[pk]-v[0])+dis(v[0]-v[i])+dis(v[i]-out);
            if(i+1<v.size())
                td+=dis(v[i+1]-out)+dis(v.back()-v[i+1]);
            ans=min(ans,td);
        }
        for(int i=0;i<v.size();i++)
        {
            double td=dis(v[pk]-v.back())+dis(v.back()-v[i])+dis(v[i]-out);
            if(i-1>=0)
                td+=dis(v[i-1]-out)+dis(v[i-1]-v[0]);
            ans=min(ans,td);
        }
        printf("%.10lf\n",ans);
    }
    else
    {
        int pk=-1;
        for(int i=1;i+1<v.size();i++)
            if(v[i].id==k)
                pk=i;
        assert(pk!=-1);
        ans=min(ans,dis(v[pk]-v[0])+dis(v[0]-out)+dis(out-v.back())+dis(v.back()-v[pk+1]));
        ans=min(ans,dis(v[pk]-v.back())+dis(v.back()-out)+dis(out-v[0])+dis(v[0]-v[pk-1]));
        ans=min(ans,dis(v[pk]-v[0])+dis(v[0]-out)+dis(out-v[pk+1])+dis(v.back()-v[pk+1]));
        ans=min(ans,dis(v[pk]-v.back())+dis(v.back()-out)+dis(out-v[pk-1])+dis(v[0]-v[pk-1]));
        for(int i=0;i<v.size();i++)
        {
            double td=dis(v[pk]-v[0])+dis(v[0]-v[i])+dis(v[i]-out);
            if(i+1<v.size())
                td+=dis(v[i+1]-out)+dis(v.back()-v[i+1]);
            ans=min(ans,td);
        }
        for(int i=0;i<v.size();i++)
        {
            double td=dis(v[pk]-v.back())+dis(v.back()-v[i])+dis(v[i]-out);
            if(i-1>=0)
                td+=dis(v[i-1]-out)+dis(v[i-1]-v[0]);
            ans=min(ans,td);
        }
        printf("%.10lf\n",ans);
    }
}