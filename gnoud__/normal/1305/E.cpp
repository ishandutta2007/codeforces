#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
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
const int N=5010,INF=1e9;
int n,m,a[N];
unordered_map<int,int> sl;
priority_queue<pii> h;
void Enter()
{
    n=in,m=in;
}
void Solve()
{
    int i=1;
    while(i<=n)
    {
        if(m<(i-1)/2) break;
        m-=(i-1)/2;
        a[i]=i;++i;
    }
    if(i>n&&m>0)
    {
        cout<<-1<<"\n";
        exit(0);
    }
    forinc(j,1,i-1) forinc(k,j+1,i-1)
    {
        int x=j+k;
        ++sl[x];
    }
    forinc(j,3,2*i-3)
    {
        int x=sl[j],y=j;
        pii tg={x,y};
        h.push(tg);
    }
    while(i<=n&&m>0)
    {
        while(!h.empty())
        {
            pii tg=h.top();h.pop();
            int u=tg.se,c=tg.fi;
            if(c>m) continue;
            if(c!=sl[u]) continue;
            if(u<=a[i-1]) continue;
            a[i]=u;
            forinc(j,1,i-1) if(a[j]+u<=1e9) h.push({++sl[a[j]+u],a[j]+u});
            m-=c;
            break;
        }
        if(!a[i])
        {
            cout<<-1<<"\n";
            exit(0);
        }
        else ++i;
    }
    int mx=a[i-1]+1;
    int cur=0;
    fordec(j,n,i) a[j]=INF-mx*(cur++);
    forinc(i,1,n) cout<<a[i]<<" ";
}
main()
{
    Enter();
    Solve();
}