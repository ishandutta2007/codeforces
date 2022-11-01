#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
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
const int N=2010;
int t,m,n,c[13][1<<12],f[13][1<<12];
vector<int> a[N],sv[1<<12];
bool cmp(vector<int> x,vector<int> y)
{
    int mx=0,my=0;
    forv(o,x) mx=max(mx,o);
    forv(o,y) my=max(my,o);
    return mx>my;
}
int main()
{
    //freopen("E2.inp","r",stdin);
    forinc(cs,1,in)
    {
        m=in,n=in;
        forinc(i,1,n) a[i].clear();
        forinc(i,1,m) forinc(j,1,n) a[j].pb(in);
        sort(a+1,a+n+1,cmp);
        int l=min(m,n);
        reset(c,0);
        forinc(i,1,l) forinc(tt,0,(1<<m)-1)
        {
            forinc(s,1,m)
            {
                int top=1,res=0;
                forinc(j,s,m) if(bit(tt,top++)) res+=a[i][j-1];
                forinc(j,1,s-1) if(bit(tt,top++)) res+=a[i][j-1];
                c[i][tt]=max(c[i][tt],res);
            }
        }
        forinc(tt,0,(1<<m)-1)
        {
            sv[tt].clear();
            forinc(tt2,0,(1<<m)-1) if((tt&tt2)==0) sv[tt].pb(tt2);
        }
        reset(f,-127);
        int oo=f[0][0];
        f[0][0]=0;
        forinc(i,0,l-1) forinc(tt,0,(1<<m)-1) if(f[i][tt]!=oo)
        forv(tt2,sv[tt]) f[i+1][tt|tt2]=max(f[i+1][tt|tt2],f[i][tt]+c[i+1][tt2]);
        cout<<f[l][(1<<m)-1]<<"\n";
    }
}