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
    forinc(test,1,in) {
        n=in;
        int ans=0;
        forinc(i,1,n) {
            a[i]=in;
            while(a[i]%2==0) a[i]/=2,ans++;
        }
        sort(a+1,a+n+1);
        forinc(i,1,ans) a[n]*=2;
        int kq=0;
        forinc(i,1,n) kq+=a[i];
        cout<<kq<<"\n";
    }
}