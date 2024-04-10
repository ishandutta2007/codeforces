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
const int N=2e5+10;
int n,a[N],f[N][2][2];
void qhd(int t1,int t2)
{
    forinc(i,1,n) forinc(j,0,1) forinc(t,0,1) f[i][j][t]=INT_MAX;
    f[2][t1][t2]=(a[2]!=t1)+(a[1]!=t2);
    forinc(i,2,n-1) forinc(j,0,1) forinc(t,0,1) if(f[i][j][t]!=INT_MAX)
    {
        //cout<<i<<" "<<j<<" "<<t<<" "<<f[i][j][t]<<"\n";
        if(!j&&!t) f[i+1][1][j]=min(f[i+1][1][j],f[i][j][t]+(!a[i+1]));
        if(j&&t) f[i+1][0][j]=min(f[i+1][0][j],f[i][j][t]+(a[i+1]));
        if(j+t==1)
        {
            f[i+1][0][j]=min(f[i+1][0][j],f[i][j][t]+(a[i+1]));
            f[i+1][1][j]=min(f[i+1][1][j],f[i][j][t]+(!a[i+1]));
        }
    }
}
int main()
{
    //freopen("baiAA.inp","r",stdin);
    forinc(cs,1,in)
    {
        n=in;
        forinc(i,1,n)
        {
            char c=getchar();
            while(c!='L'&&c!='R') c=getchar();
            a[i]=(c=='R');
        }
        int ans=INT_MAX;
        qhd(0,0);
        ans=min({ans,f[n][1][0],f[n][1][1]});
        qhd(1,0);
        ans=min({ans,f[n][1][0],f[n][1][1],f[n][0][1]});
        qhd(0,1);
        ans=min({ans,f[n][0][0],f[n][0][1],f[n][1][0]});
        qhd(1,1);
        ans=min({ans,f[n][0][0],f[n][0][1]});
        cout<<ans<<"\n";
    }
}