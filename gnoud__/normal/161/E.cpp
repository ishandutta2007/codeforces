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
const int N=110000;
int T,n,p[N],pw[N],a[N],c[N][6],f[N][6],ans[1010][1010];
vector<int> e[N][6];
void Enter()
{
    pw[0]=1;
    forinc(i,1,5) pw[i]=pw[i-1]*10;
    p[1]=1;
    forinc(i,2,pw[5]-1) if(!p[i])
    for(int j=i*2;j<=pw[5]-1;j+=i) p[j]=i;
    forinc(i,1,pw[5]-1) if(!p[i])
    {
        int x=i;
        fordec(j,5,1) c[i][j]=x%10,x/=10;
        forinc(j,1,5)
        {
            f[i][j]=f[i][j-1]*10+c[i][j];
            e[f[i][j]][j].pb(i);
        }
    }
    forinc(i,0,pw[3]-1) forinc(j,0,pw[3]-1) forv(x,e[i][3]) ans[i][j]+=e[j*10+c[x][5]][4].size();
}
int duyet(int i)
{
    if(i==n+1) return 1;
    int ret=0;
    forinc(j,1,pw[n-i+1]-1)
    {
        int pre=0;
        forinc(_i,1,i-1) pre=pre*10+c[a[_i]][i+5-n];
        a[i]=pre*pw[n-i+1]+j;
        if(!p[a[i]]) ret+=duyet(i+1);
    }
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("161E.inp","r",stdin);
    Enter();
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        n=s.size();
        reset(a,0);
        forv(x,s) a[1]=a[1]*10+x-'0';
        if(s.size()<=4) cout<<duyet(2)<<"\n";
        else
        {
            int res=0;
            forv(i,e[c[a[1]][2]][1]) forv(j,e[c[a[1]][3]*10+c[i][3]][2])
            res+=ans[c[a[1]][4]*100+c[i][4]*10+c[j][4]][c[a[1]][5]*100+c[i][5]*10+c[j][5]];
            cout<<res<<"\n";
        }
    }
}