#include<bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=200010;
int n,e,a[N],p[N*5];
ll f[N][2];
string s;
main() {
    //freopen("1609.inp","r",stdin);
    forinc(i,1,1e6) p[i]=i;
    forinc(i,2,1e3) if(p[i]==i) for(int j=i+i;j<=1e6;j+=i) p[j]=i;
    forinc(test,1,in) {
        n=in,e=in;
        int du=0;
        forinc(i,1,n) {
            int aa=in;
            if(aa==1) a[i]=0; else a[i]=p[aa]==aa?1:2;
        }
        ll ans=0;
        fordec(i,n,1) {
            if(a[i]==2) continue;
            if(i+e>n) f[i][a[i]]++;
            else {
                f[i][a[i]]++;
                if(a[i]==0) f[i][a[i]+1]+=f[i+e][1];
                f[i][a[i]]+=f[i+e][0];
            }
            ans+=f[i][1]-a[i];
        }
        cout<<ans<<"\n";
        forinc(i,1,n) f[i][0]=f[i][1]=0;
    }
}