#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
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
const int N=1e5+10;
int n,a[N];
main()
{
    n=in;
    forinc(i,1,n) a[i]=in;
    if(n==1)
    {
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
                cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
                cout<<1<<" "<<1<<"\n";
        cout<<-a[1]<<"\n";
        return 0;
    }
    cout<<1<<" "<<1<<"\n";
    cout<<-a[1]<<"\n";
    cout<<2<<" "<<n<<"\n";
    forinc(i,2,n) cout<<a[i]*(n-1)<<" ";cout<<"\n";
    cout<<1<<" "<<n<<"\n";
    cout<<0<<" ";
    forinc(i,2,n) cout<<-a[i]*n<<" ";
}