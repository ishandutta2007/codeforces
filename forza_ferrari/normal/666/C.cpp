#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int lim=1e5,mod=1e9+7;
string s;
int n,len,ans[100001],cnt,fac[100001],inv[100001];
vector<pair<int,int> > v[100001];
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline int c(int x,int y)
{
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    fac[0]=inv[0]=1;
    for(int i=1;i<=lim;++i)
        fac[i]=1ll*fac[i-1]*i%mod;
    inv[lim]=pw(fac[lim],mod-2);
    for(int i=lim-1;i;--i)
        inv[i]=1ll*inv[i+1]*(i+1)%mod;
    cin>>n>>s;
    len=s.length();
    for(int i=1;i<=n;++i)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            cin>>s;
            len=s.length();
        }
        else
        {
            int x;
            cin>>x;
            v[len].emplace_back(x-len,++cnt);
        }
    }
    for(int i=1;i<=lim;++i)
        if(!v[i].empty())
        {
            sort(v[i].begin(),v[i].end());
            int p=0,res=0,w=1;
            for(auto j:v[i])
            {
                for(;p<=j.first;++p)
                {
                    res=(26ll*res%mod+1ll*c(p+i-1,i-1)*w%mod)%mod;
                    w=25ll*w%mod;
                }
                ans[j.second]=res;
            }
        }
    for(int i=1;i<=cnt;++i)
        cout<<ans[i]<<'\n';
    return 0;
}