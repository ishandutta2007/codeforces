#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define PB push_back
#define DB pop_back
#define V(a) vector<a>

static const int N=(1<<18)+5, M=998244353, G=3;
static int fc[N],fci[N],inv[N],rev[N],rt[N];

int powM(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=1LL*ans*x%M;
        x=1LL*x*x%M;
        y>>=1;
    }
    return ans;
}

void fft(V(ll) &a,ll n,bool invert)
{
    for(int i=1; i<n; i++)
    {
        if(rev[n+i]>i)
        {
            swap(a[i],a[rev[n+i]]);
        }
    }
    for(int s=1; s<n; s<<=1)
    {
        for(int j=0; j<n; j+=(s<<1))
        {
            for(int i=0; i<s; i++)
            {
                ll tmp=(rt[s+i]*a[i+j+s])%M;

                a[i+j+s]=a[i+j]-tmp;
                if(a[i+j+s]<0) a[i+j+s]+=M;

                a[i+j]=a[i+j]+tmp;
                if(a[i+j]>M) a[i+j]-=M;
            }
        }
    }
    if(invert)
    {
        int invn=inv[n];
        REP(i,0,n)
        {
            a[i]=(a[i]*invn)%M;
        }
        reverse(a.begin()+1,a.end());
    }
    return;
}

void PolyMult(V(ll) &a,V(ll) &b,V(ll) &v)
{
    ll n=1;
    while(n<((ll)a.size())+((ll)b.size()))
    { 
        n<<=1;
    }
    V(ll) fa(a.begin(),a.end());
    fa.resize(n,0);
    V(ll) fb(b.begin(),b.end());
    fb.resize(n,0);
    fft(fa,n,false);
    fft(fb,n,false);
    v.resize(n,0);
    REP(i,0,n)
    {
        v[i]=((fa[i]*fb[i])%M);
    }
    fft(v,n,true);
    v.resize(((ll)a.size())+((ll)b.size())-1,0LL);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fc[0]=1;
    REP(i,1,N) fc[i] = 1LL*fc[i-1]*i % M;

    fci[N-1]=powM(fc[N-1], M-2);
    REPI(i,0,N-1) fci[i] = 1LL*fci[i+1]*(i+1) % M;

    REP(i,1,N) inv[i] = 1LL*fci[i]*fc[i-1]%M;

    rev[1]=0;
    for(int s=2; (s<<1)<=N; s<<=1)
    {
        for(int i=0; i<(s>>1); i++)
        {
            rev[s+i]=(rev[(s>>1)+i]<<1);
            rev[s+(s>>1)+i]=((rev[(s>>1)+i]<<1)|1);
        }
    }

    int tmpp=powM(G, (M-1)/(1<<18));
    rt[1<<17]=1;
    for(int i=(1<<17)+1; i<(1<<18); i++)
    {
        rt[i]=1LL*rt[i-1]*tmpp%M;
    }
    for(int i=(1<<17)-1; i>=1; i--)
    {
        rt[i]=rt[i<<1];
    }

    ll n;
    cin>>n;
    V(ll) v={1};
    while(n--)
    {
        ll a,b;
        cin>>a>>b;

        ll nv=v.size();

        V(ll) tmp(2*nv+a-b,0LL);
        REP(i,b-nv,a+nv)
        {
            if(i>=0&&i<=a+b)
            {
                tmp[i-(b-nv)]=1LL*fc[a+b]*fci[i]%M*fci[a+b-i]%M;
            }
        }

        V(ll) ans;
        PolyMult(v,tmp,ans);

        V(ll) newv(nv+a-b,0LL);
        REP(i,0,nv+a-b)
        {
            newv[i]=ans[i+nv];
        }

        v=newv;
    }

    ll ans=0;
    for(auto it:v) ans = (ans+it)%M;
    cout<<ans;

    return 0;
}