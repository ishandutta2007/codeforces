#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=3e5+3;
int n,a[mxn],nx[mxn][2],px[mxn];ll s[mxn];

bool cmp1(int x,int y){return s[x]<s[y];}
struct arrrrr{
    int a[mxn];void clr(){for(int i=1;i<=n+1;++i)a[i]=0;}
    void add(int x,int y){++x;for(;x<=n+1;x+=x&-x)a[x]+=y;}
    int ask(int x){++x;int r=0;for(;x;x&=x-1)r+=a[x];return r;}
    int erf(int v){
        int z=0,x=0;for(int i=1<<20;i;i>>=1)if(x+i<=n+1){
            x+=i;if(z+a[x]<=v)z+=a[x];else x-=i;
        }
        return x-1;
    }
}r1,r2;
int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
        for(int i=1;i<=n;++i)if(i&1)s[i]=s[i-1]+a[i];else s[i]=s[i-1]-a[i];
        for(int i=0;i<=n;++i)px[i]=i;sort(px,px+n+1,cmp1);
        ll ans=0;
        r1.clr();for(int i=2;i<=n;i+=2)r1.add(i,1);
        for(int l=0,r;l<=n;l=r+1){
            r=l;while(r!=n&&s[px[r+1]]==s[px[l]])++r;
            for(int i=l;i<=r;++i)r2.add(px[i],1);
            for(int i=l;i<=r;++i)if(px[i]%2==0)r1.add(px[i],-1);
            for(int i=l;i<=r;++i){
                int x=px[i];//if(x%2)continue;
                int y=r1.erf(r1.ask(x));
                assert(y>=x);
                ans+=r2.ask(y)-r2.ask(x);
//                cout<<x<<' '<<y<<' '<<r2.ask(y)-r2.ask(x)<<endl
            }
            for(int i=l;i<=r;++i)r2.add(px[i],-1);
            for(int i=l;i<=r;++i)if(px[i]%2)r1.add(px[i],1);
        }
        /*
        r1.clr();for(int i=1;i<=n;i+=2)r1.add(i,1);
        for(int l=0,r;l<=n;l=r+1){

            r=l;while(r!=n&&s[px[r+1]]==s[px[l]])++r;
            cout<<l<<' '<<r<<endl;
            for(int i=l;i<=r;++i)r2.add(px[i],1);
                                              for(int j=1;j<=n;++j)cout<<r1.ask(j)-r1.ask(j-1);puts("");
            for(int i=l;i<=r;++i)if(px[i]%2)r1.add(px[i],-1);
                                  for(int j=1;j<=n;++j)cout<<r1.ask(j)-r1.ask(j-1);puts("");
            for(int i=l;i<=r;++i){
                int x=px[i];if(x%2==0)continue;
                for(int j=1;j<=n;++j)cout<<r1.ask(j)-r1.ask(j-1);puts("");
                int y=r1.erf(r1.ask(x));
                                cout<<x<<' '<<y<<' '<<r2.ask(y)-r2.ask(x)<<endl;
                                assert(y>=x);
                ans+=r2.ask(y)-r2.ask(x);
            }
            for(int i=l;i<=r;++i)r2.add(px[i],-1);
            for(int i=l;i<=r;++i)if(px[i]%2==0)r1.add(px[i],1);
        }*/
        printf("%lld\n",ans);
    }
    return 0;
}