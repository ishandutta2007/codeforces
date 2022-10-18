#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define int long long
int n,len,x,y;
vector<pair<int,int> > v;
vector<char> t;
int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
signed main()
{
    scanf("%lld",&n);
    v.push_back(make_pair(n,n));
    t.push_back('^');
    len=ceil(log2(n+1))-1;
    int tmp=n;
    for(register int i=1;i<=len;++i)
    {
        v.push_back(make_pair(tmp,tmp));
        t.push_back('+');
        tmp<<=1;
    }
    v.push_back(make_pair(n,tmp));
    t.push_back('^');
    tmp^=n;
    int a=tmp,b=n,c=1;
    int d=exgcd(a,b,x,y);
    int p=b/d,q=a/d;
    x*=c/d;
    y*=c/d;
    if(x>=0)
    {
        int k=(x-1)/p;
        x-=p*k;
        y+=q*k;
    }
    x-=p;
    y+=q;
    x=-x;
    while((tmp*x)^(n*y)^1)
    {
        x+=p;
        y+=q;
    }
    for(register int i=1;1ll<<i<=x;++i)
    {
        v.push_back(make_pair(tmp<<(i-1),tmp<<(i-1)));
        t.push_back('+');
    }
    int qwq=0;
    for(register int i=0;1ll<<i<=x;++i)
        if((1ll<<i)&x)
        {
            v.push_back(make_pair(qwq,tmp<<i));
            t.push_back('+');
            qwq+=tmp<<i;
        }
    for(register int i=1;1ll<<i<=y;++i)
    {
        v.push_back(make_pair(n<<(i-1),n<<(i-1)));
        t.push_back('+');
    }
    qwq=0;
    for(register int i=0;1ll<<i<=y;++i)
        if((1ll<<i)&y)
        {
            v.push_back(make_pair(qwq,n<<i));
            t.push_back('+');
            qwq+=n<<i;
        }
    v.push_back(make_pair(tmp*x,n*y));
    t.push_back('^');
    printf("%lld\n",(int)v.size());
    for(register int i=0;i<(int)v.size();++i)
        printf("%lld %c %lld\n",v[i].first,t[i],v[i].second);
    return 0;
}