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
const int N=2010;
int n,k,f[N][N],bd[N][N],t[N];
string a[N],s[N];
int g(string a,string b)
{
    int ret=0;
    forinc(i,0,6)
    {
        if(a[i]=='1'&&b[i]=='0') return -1;
        if(a[i]=='0'&&b[i]=='1') ret++;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("baiB.inp","r",stdin);
    cin>>n>>k;
    forinc(i,1,n) cin>>s[i];
    a[0]="1110111",a[1]="0010010",a[2]="1011101";
    a[3]="1011011",a[4]="0111010",a[5]="1101011";
    a[6]="1101111",a[7]="1010010",a[8]="1111111",a[9]="1111011";
    f[n+1][0]=1;
    forinc(i,1,n) forinc(j,0,9) bd[i][j]=g(s[i],a[j]);
    fordec(i,n,1) forinc(j,0,k) if(f[i+1][j])
    forinc(t,0,9) if(bd[i][t]!=-1&&j+bd[i][t]<=k) f[i][j+bd[i][t]]=1;
    if(!f[1][k]) return cout<<-1,0;
    forinc(i,1,n)
    {
        fordec(j,9,0) if(bd[i][j]!=-1&&f[i+1][k-bd[i][j]])
        {
            cout<<j;
            k-=bd[i][j];
            break;
        }
    }
}