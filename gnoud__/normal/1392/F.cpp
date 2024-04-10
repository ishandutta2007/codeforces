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
const int N=1e6+10;
int n,kq[N],p[N],t[4*N];
void build(int s,int l,int r)
{
    if(l==r)
    {
        t[s]=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=t[2*s]+t[2*s+1];
}
void Init(int &h,int &ret,int &s)
{
    forinc(i,1,n)
    {
        int x=in;
        int y=x-h;
        s+=i-1;
        ret+=y;
        int l=0,r=1e12;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(ret-m<=s) r=m-1;
            else if(ret-m*i<=s) r=m-1;
            else l=m+1;
        }
        ret-=l*i;
        h+=l;
    }
}
void cal(int ret)
{
    build(1,1,n);
    forinc(i,1,n)
    {
        if(i*(i+1)/2>=ret)
        {
            ret-=i*(i-1)/2;
            forinc(j,1,i-1) kq[n-j+1]=i-j;
            forinc(j,1,ret) ++kq[n-i+j];
            break;
        }
    }
}
main()
{
    //freopen("baiF.inp","r",stdin);
    n=in;
    forinc(i,2,n) if(!p[i])
    for(int j=i;j<=n;j+=i) p[j]=i;
    int h=0,ret=0,s=0;
    Init(h,ret,s);
    cal(ret);
    forinc(i,1,n) cout<<kq[i]+h<<" ";
}