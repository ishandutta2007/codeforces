#include <bits/stdc++.h>

using namespace std;

#define mem(a,x) memset((a),(x),sizeof((a)))
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define lp(i,l,r) for(int i=l;i<=r;i++)
#define rlp(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

typedef pair<int,int> PII;
typedef long long LL;
const LL mod=1e9+7;
int vis[100];
int cnt=0;
int pri[200];
int get_pri()
{
    for(int i=2;i<=70;i++)
    {
        if(!vis[i]){
            pri[cnt++]=i;
            int now=i;
            while(now<=70)
            {
                vis[now]=1;
                now+=i;
            }
        }
    }
    return cnt;
}

LL qpow(int k)
{
    LL res=1;
    LL now=2;
    while(k>0)
    {
        if(k&1)
            res*=now;
        //cout<<k<<' '<<now<<endl;
        now*=now;
        now%=mod;
        res%=mod;
        k>>=1;
    }
    return res;
}

vector<int>base;


int main()
{
    int len=get_pri();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,t=0;
        scanf("%d",&a);
        for(int j=0;j<len;j++)if(a%pri[j]==0)
            while(a%pri[j]==0) a/=pri[j],t^=(1<<j);
        for(int j=0;j<base.size();j++)
            t=min(t,t^base[j]);
        if(t)base.pb(t);
    }
    //cout<<base.size()<<endl;
    LL res=qpow(n-base.size());
    cout<<(res+mod-1)%mod<<endl;
    return 0;
}