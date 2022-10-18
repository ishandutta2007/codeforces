#include<iostream>
#include<cstdio>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
int n,a[1000001],p[1000001],lim,ans;
map<int,int,greater<> > mp;
vector<int> w;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
signed main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[p[i]=i]=read();
    shuffle(p+1,p+n+1,rnd);
    lim=min(n,12ll);
    for(int i=1;i<=lim;++i)
    {
        w.clear();
        mp.clear();
        int tmp=a[p[i]];
        for(int j=2;j*j<=tmp;++j)
            if(tmp%j==0)
            {
                w.emplace_back(j);
                while(tmp%j==0)
                    tmp/=j;
            }
        if(tmp^1)
            w.emplace_back(tmp);
        sort(w.begin(),w.end());
        tmp=a[p[i]];
        for(int j=1;j*j<=tmp;++j)
            if(tmp%j==0)
            {
                mp[j]=mp[tmp/j]=0;
            }
        for(int j=1;j<=n;++j)
            ++mp[gcd(tmp,a[j])];
        for(int i:w)
            for(auto &j:mp)
                if(mp.count(j.first*i))
                    j.second+=mp[j.first*i];
        for(auto i:mp)
            if((i.second<<1)>=n)
            {
                ans=max(ans,i.first);
                break;
            }
    }
    cout<<ans<<'\n';
    return 0;
}