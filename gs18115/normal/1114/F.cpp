#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MOD=1e9+7;
const LL bound=3<<19;
inline LL Pow(LL x,LL y)
{
    LL ret=1;
    while(y>0)
    {
        if(y&1)
            ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}
inline LL inv(LL x)
{
    return Pow(x,MOD-2);
}
struct seg1
{
    int data[bound],lazy[bound];
    seg1()
    {
        fill(data,data+bound,1);
        fill(lazy,lazy+bound,1);
    }
    void SS(int N,int s,int e,int S,int E,int x)
    {
        if(s>E||S>e)
            return;
        if(s>=S&&E>=e)
        {
            lazy[N]=(LL)lazy[N]*x%MOD;
            return;
        }
        data[N]=(LL)data[N]*Pow(x,min(E,e)-max(S,s)+1)%MOD;
        int m=s+e>>1;
        SS(N<<1,s,m,S,E,x);
        SS(N<<1|1,m+1,e,S,E,x);
        return;
    }
    LL SM(int N,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return 1;
        data[N]=(LL)data[N]*Pow(lazy[N],e-s+1)%MOD;
        int l=N<<1;
        int r=l|1;
        if(r<bound)
        {
            lazy[l]=(LL)lazy[l]*lazy[N]%MOD;
            lazy[r]=(LL)lazy[r]*lazy[N]%MOD;
        }
        lazy[N]=1;
        if(s>=S&&E>=e)
            return data[N];
        int m=s+e>>1;
        return SM(l,s,m,S,E)*SM(r,m+1,e,S,E)%MOD;
    }
}mul;
struct seg2
{
    LL data[bound],lazy[bound];
    seg2()
    {
        for(int i=0;i<bound;i++)
            data[i]=lazy[i]=0;
    }
    void SS(int N,int s,int e,int S,int E,LL x)
    {
        if(s>E||S>e)
            return;
        if(s>=S&&E>=e)
        {
            lazy[N]|=x;
            return;
        }
        data[N]|=x;
        int m=s+e>>1;
        SS(N<<1,s,m,S,E,x);
        SS(N<<1|1,m+1,e,S,E,x);
        return;
    }
    LL SM(int N,int s,int e,int S,int E)
    {
        if(s>E||S>e)
            return 0;
        data[N]|=lazy[N];
        int l=N<<1;
        int r=l|1;
        if(r<bound)
        {
            lazy[l]|=lazy[N];
            lazy[r]|=lazy[N];
        }
        lazy[N]=0;
        if(s>=S&&E>=e)
            return data[N];
        int m=s+e>>1;
        return SM(l,s,m,S,E)|SM(r,m+1,e,S,E);
    }
}pl;
vector<int>prime;
int i,j;
int N,Q,L,R,x;
LL in;
int A[401234];
LL calc[401234];
bool chk[321];
char S[12];
LL ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=2;i<=300;i++)
    {
        if(!chk[i])
            prime.push_back(i);
        for(j=i*i;j<=300;j+=i)
            chk[j]=true;
    }
    for(i=0;i<prime.size();i++)
        calc[i]=(prime[i]-1)*inv(prime[i])%MOD;
    cin>>N>>Q;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        mul.SS(1,0,N-1,i,i,A[i]);
        in=0;
        for(j=0;j<prime.size();j++)
            if(A[i]%prime[j]==0)
                in|=1LL<<j;
        pl.SS(1,0,N-1,i,i,in);
    }
    while(Q-->0)
    {
        cin>>S;
        if(S[0]=='T')
        {
            cin>>L>>R;
            ans=mul.SM(1,0,N-1,--L,--R);
            in=pl.SM(1,0,N-1,L,R);
            for(i=0;i<prime.size();i++)
                if(in>>i&1)
                    ans=ans*calc[i]%MOD;
            cout<<ans<<'\n';
        }
        else
        {
            cin>>L>>R>>x;
            mul.SS(1,0,N-1,--L,--R,x);
            in=0;
            for(i=0;i<prime.size();i++)
                if(x%prime[i]==0)
                    in|=1LL<<i;
            pl.SS(1,0,N-1,L,R,in);
        }
    }
    cout<<endl;
    return 0;
}