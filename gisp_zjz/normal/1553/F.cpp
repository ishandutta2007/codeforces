#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=3e5+7;
const int N=300000;
const int B=2000;
struct bits{
    ll b[maxn];
    void init(){memset(b,0,sizeof(b));}
    void add(int x,ll y){
        while (x<maxn) b[x]+=y,x+=x&(-x);
    }
    ll qry(ll x){
        ll ret=0;
        while (x) ret+=b[x],x-=x&(-x);
        return ret;
    }
}cnt,sum;
ll a[maxn],f[B+5],g[B+5];
int n;
int main(){
    scanf("%d",&n);
    cnt.init(); sum.init();
    ll ans=0;
    for (int i=0;i<n;i++){
        int x;scanf("%d",&x);
        ans+=sum.qry(N);
        ans+=1ll*i*x;
        if (x<=B) ans-=f[x]*x;
        else {
            ll res=0;
            for (int j=1;j*x<=N;j++){
                res+=(cnt.qry(min(N,(j+1)*x-1))-cnt.qry(j*x-1))*j;
            }
            ans-=res*x;
        }
        for (int j=1;j<=B;j++) ans-=g[j]*(x/j)*j,f[j]+=x/j;
        for (int j=1;j<=N/B;j++){
            ans-=(sum.qry(max(x/j,B))-sum.qry(max(x/(j+1),B)))*j;
        }
        cnt.add(x,1); sum.add(x,x);
        if (x<=B) g[x]++;
        printf("%lld ",ans);
    }
    puts("");
    return 0;
}