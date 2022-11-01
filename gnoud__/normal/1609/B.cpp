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
int n,q,f[N];
string s;
main() {
    //freopen("1609.inp","r",stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q>>s;
    s=" "+s;
    int ret=0;
    forinc(i,3,n) f[i]=s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a',ret+=f[i];
    while(q--) {
        int x;
        char c;
        cin>>x>>c;
        s[x]=c;
        forinc(i,x,x+2){
            if(i<3||i>n) continue;
            ret-=f[i];
            f[i]=s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a';
            ret+=f[i];
        }
        cout<<ret<<"\n";
    }
}