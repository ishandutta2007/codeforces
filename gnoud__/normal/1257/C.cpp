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
const int N=2e5+5;
int n,a[N],dd[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=1e17;
        forinc(i,1,n)
        {
            cin>>a[i];
            dd[i]=0;
        }
        forinc(i,1,n) dd[i]=0;
        forinc(j,1,n) dd[j]=0;
        int rightt=1;
        forinc(i,1,n)
        {
            int tg=a[i];
            ++dd[tg];
            while(dd[tg]==2)
            {
                dd[a[rightt]]--;
                rightt++;
                ans=min(ans,i-rightt+2);
            }
        }
        if(ans!=1e17) {cout<<ans<<"\n";continue;}
        cout<<-1<<"\n";
    }
}