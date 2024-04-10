#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i=(a);i<=(n);i++)
#define per(i,a,n) for(auto i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int maxn = 300000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
template<class T> struct BIT
{
    int n;
    T a[maxn+5];
    void init(int _n)
    {
        n=_n;
        rep(i,1,n) a[i]=0;
    }
    void add(int i,T x)
    {
        for(;i<=n;i+=i&-i) a[i]+=x;
    }
    T ask(int i)
    {
        T ans=0;
        for(;i;i-=i&-i) ans+=a[i];
        return ans;
    }
    T ask(int l,int r) {return ask(r)-ask(l-1);}
};
BIT<int> CNT;
BIT<ll> SUM;

int a[maxn+5];
ll ans[maxn+5];
int cnt[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    SUM.init(maxn);
    CNT.init(maxn);
    rep(_,1,n)
    {
        int x=a[_];
        ll res=SUM.ask(x-1);
        ll preS=res; int preC=CNT.ask(x-1);
        rep(i,1,maxn)
        {
            int l=i*x-1,r=(i+1)*x-1;
            if(l>maxn) break;
            if(r>maxn) r=maxn;
            ll tmpS=SUM.ask(r);
            int tmpC=CNT.ask(r);
            res+=tmpS-preS-1ll*(tmpC-preC)*(i*x);
            preS=tmpS;
            preC=tmpC;
        }
        res+=1ll*x*CNT.ask(x+1,maxn);
        //printf("? %d %lld\n",_,res);
        if(CNT.ask(x-1)>0)
        {
            int l=1;
            ll preS=-1,preC=-1;
            while(l<=x)
            {
                int val=x/l;
                int r=x/val;
                if(r-l+1<=6) 
                {
                    ll s=0,c=0;
                    rep(i,l,r) s+=cnt[i]*i,c+=cnt[i];
                    res+=1ll*x*c-s*val;
                    preS=preC=-1;
                }
                else
                {
                    ll s=-preS,c=-preC;
                    if(s==1)
                    {
                        s=-SUM.ask(l-1);
                        c=-CNT.ask(l-1);
                    }
                    preS=SUM.ask(r);
                    preC=CNT.ask(r);
                    s+=preS;
                    c+=preC;
                    res+=1ll*x*c-s*val;
                }

                l=r+1;
            }
        }
        SUM.add(x,x);
        CNT.add(x,1);
        cnt[x]++;

        ans[_]=ans[_-1]+res;
    }
    rep(i,1,n) printf("%lld%c",ans[i]," \n"[i==n]);
    return 0; 
}