#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define int long long
int n,m,b,g,d,ans,x[100001],y[100001];
vector<int> v[200001][2];
map<int,int> mp;
struct element
{
    int x,y;
    element(int x_,int y_):
        x(x_),y(y_){}
    bool operator <(const element &other) const
    {
        return y<other.y;
    }
};
vector<element> w;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
inline void exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
inline int solve(vector<int> &x,vector<int> &y)
{
    if(y.size()==m)
        return -1;
    if(!(x.size()|y.size()))
    {
        cout<<"-1\n";
        exit(0);
    }
    mp.clear();
    w.clear();
    for(int i:y)
        mp[i]=i;
    for(int i:x)
        if(mp.count(i%m))
            mp[i%m]=min(mp[i%m],i);
        else
            mp[i%m]=i;
    for(auto i:mp)
    {
        int l,r;
        exgcd(n,m,l,r);
        int t=l*i.first;
        t+=m*(int)ceil(1.0*(1-t)/m);
        if(t==m)
            t-=m;
        w.emplace_back(i.second,t);
        //cout<<i.second<<" "<<t<<'\n';
    }
    sort(w.begin(),w.end());
    int res=w.size()>1? w.back().x+(m+w[0].y-w.back().y-1)*n:w[0].x+(m-1)*n;
    for(int i=1;i<(int)w.size();++i)
        res=max(res,w[i-1].x+(w[i].y-w[i-1].y-1)*n);
    return res;
}
signed main()
{
    n=read(),m=read(),b=read();
    for(int i=1;i<=b;++i)
        x[i]=read();
    g=read();
    for(int i=1;i<=g;++i)
        y[i]=read();
    d=gcd(n,m);
    if(d>b+g)
    {
        cout<<"-1\n";
        return 0;
    }
    n/=d,m/=d;
    for(int i=1;i<=b;++i)
        v[x[i]%d][0].emplace_back(x[i]/d);
    for(int i=1;i<=g;++i)
        v[y[i]%d][1].emplace_back(y[i]/d);
    for(int i=0;i<d;++i)
    {
        int tmp=solve(v[i][0],v[i][1]);
        if(tmp>=0)
        {
            //cout<<tmp<<'\n';
            ans=max(ans,tmp*d+i);
        }
    }
    swap(n,m);
    for(int i=0;i<d;++i)
    {
        swap(v[i][0],v[i][1]);
        int tmp=solve(v[i][0],v[i][1]);
        if(tmp>=0)
        {
            //cout<<tmp<<'\n';
            ans=max(ans,tmp*d+i);
        }
    }
    cout<<ans<<'\n';
    return 0;
}