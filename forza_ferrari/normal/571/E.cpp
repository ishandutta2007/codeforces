#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<random>
#include<chrono>
using namespace std;
#define int long long
const int mod=1000000007;
int n,s[101],g[101],f[101],cnt[101];
map<int,int> mp;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
pair<int,int> a[101];
inline int pw(int a,int b,int val,int mod)
{
    int res=val;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
inline int gcd(int x,int y)
{
    if(!x||!y)
        return x|y;
    return x%y? gcd(y,x%y):y;
}
inline bool check(int val)
{
    for(int i=1;i<=n;++i)
    {
        if(val%a[i].first)
            return 0;
        if(val==a[i].first)
            continue;
        if(a[i].second==1)
            return 0;
        int w=a[i].first;
        while(w<val)
            w*=a[i].second;
        if(w^val)
            return 0;
    }
    return 1;
}
inline bool check(int x,int y,int p)
{
    int w=(p*log(a[x].second)+log(a[x].first)-log(a[y].first))/log(a[y].second)+0.5;
    for(int k=max(0ll,w-10);k<=min(2000ll,w+10);++k)
    {
        int flag=1;
        for(int q=0;q<=4;++q)
        {
            int m=rnd()%mod+1e9;
            if(pw(a[x].second,p,a[x].first,m)!=pw(a[y].second,k,a[y].first,m))
            {
                flag=0;
                break;
            }
        }
        if(flag)
            return 1;
    }
    return 0;
}
inline void solve(int x,int y)
{
    for(int i=0;i<=2000;++i)
        if(check(x,y,i))
        {
            int flag=1;
            for(int j=1;j<=n;++j)
                if(!check(x,j,i))
                {
                    flag=0;
                    break;
                }
            if(flag)
            {
                cout<<pw(a[x].second,i,a[x].first,mod)<<'\n';
                exit(0);
            }
        }
    cout<<"-1\n";
    exit(0);
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1);
    if(check(a[n].first))
    {
        cout<<a[n].first<<'\n';
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        mp.clear();
        int x=a[i].second;
        for(int i=2;i*i<=x;++i)
            while(x%i==0)
            {
                x/=i;
                ++mp[i];
            }
        if(x^1)
            ++mp[x];
        s[i]=1;
        for(auto j:mp)
            g[i]=gcd(g[i],j.second);
        for(auto &j:mp)
        {
            j.second/=g[i];
            for(int k=1;k<=j.second;++k)
                s[i]*=j.first;
        }
        if(s[1]^s[i])
            solve(1,i);
    }
    int m=1,tmp=0;
    for(int i=1;i<=n;++i)
    {
        f[i]=a[i].first;
        while(f[i]%s[i]==0)
        {
            f[i]/=s[i];
            ++cnt[i];
        }
        if(f[1]^f[i])
        {
            cout<<"-1\n";
            return 0;
        }
        int x=gcd(g[i],m);
        if(tmp%x!=cnt[i]%x)
        {
            cout<<"-1\n";
            return 0;
        }
        while(tmp%g[i]!=cnt[i]%g[i])
            tmp+=m;
        m=m/x*g[i];
        tmp%=m;
    }
    for(int i=1;i<=n;++i)
        while(tmp<cnt[i])
            tmp+=m;
    cout<<pw(s[1],tmp,f[1],mod)<<'\n';
    return 0;
}