#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mod=998244353;
inline int gcd2(int x,int y)
{
    while(y>0)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(ll)x*y%mod;
}
inline int pw(int x,int y)
{
    int r=1;
    while(y>0)
    {
        if(y%2==1)
            r=mul(r,x);
        x=mul(x,x);
        y/=2;
    }
    return r;
}
inline int inv(int x)
{
    return pw(x,mod-2);
}
inline int div2(int x,int y)
{
    return mul(x,inv(y));
}
inline int nc2(int x)
{
    return mul(x,sub(x,1));
}
const int MXN=1e6+10;
int fact[MXN],invf[MXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0]=1;
    for(int i=1;i<MXN;i++)
        fact[i]=mul(i,fact[i-1]);
    invf[MXN-1]=inv(fact[MXN-1]);
    for(int i=MXN;--i>0;)
        invf[i-1]=mul(i,invf[i]);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>ct(n+1,0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            ct[x]++;
        }
        vector<int>ctv;
        for(int&t:ct)
            if(t!=0)
                ctv.eb(t);
        if((int)ctv.size()==1)
        {
            cout<<1<<'\n';
            continue;
        }
        int g=0;
        for(int&t:ctv)
            g=gcd2(g,t);
        vector<int>divis;
        for(int i=0;i++<g;)
            if(g%i==0)
                divis.eb(i);
        vector<int>ansv,hapv;
        for(int&p:divis)
        {
            vector<int>nv;
            for(int&t:ctv)
                nv.eb(t/p);
            int nn=n/p;
            int ca=fact[nn];
            for(int&t:nv)
                ca=mul(ca,invf[t]);
            int co=0;
            for(int&t:nv)
                if(t>1)
                    co=add(co,mul(ca,mul(mul(invf[nn],fact[nn-2]),mul(fact[t],invf[t-2]))));
            co=sub(1,mul(co,inv(ca)));
            ansv.eb(ca);
            hapv.eb(mul(ca,mul(co,n)));
        }
        int m=divis.size();
        for(int i=m;i-->0;)
            for(int j=i;j-->0;)
                if(divis[i]%divis[j]==0)
                    ansv[j]=sub(ansv[j],ansv[i]),hapv[j]=sub(hapv[j],hapv[i]);
        int ans=0,act=0;
        for(int i=0;i<m;i++)
        {
            int asdf=inv(n/divis[i]);
            int cct=mul(ansv[i],asdf);
            act=add(act,cct);
            int cans=mul(hapv[i],asdf);
            ans=add(ans,cans);
        }
        cout<<mul(ans,inv(act))<<'\n';
    }
    return 0;
}