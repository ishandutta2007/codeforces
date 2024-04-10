// Author -- Frame

#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005,mod=1000000007,MOD=1000000006;
Finline void add(ll &a,const ll &b){(a+=b)>=MOD&&(a-=MOD);}
int size;
struct matrix{
    ll a[6][6];
    Finline matrix(){memset(a,0,sizeof(a));}
    matrix operator * (const matrix &b)const
    {
        matrix c;
        for(register int i=1;i<=size;++i)
        {
            for(register int k=1;k<=size;++k)
            {
                for(register int j=1;j<=size;++j)
                {
                    add(c.a[i][j],1ll*a[i][k]*b.a[k][j]%MOD);
                }
            }
        }
        return c;
    }
}f,cs;
matrix ksm(matrix a,ll b)
{
    matrix res;
    for(int i=1;i<=size;++i) res.a[i][i]=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a,b>>=1;
    }
    return res;
}
ll Ksm(ll a,ll b)
{
    b%=MOD;
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}
int main()
{
    ll n,f1,f2,f3,c;
    read(n,f1,f2,f3,c);
    cs.a[1][1]=cs.a[1][2]=cs.a[1][3]=cs.a[2][1]=cs.a[3][2]=cs.a[4][4]=cs.a[4][5]=cs.a[5][5]=1;
    cs.a[1][4]=2,cs.a[1][5]=MOD-4;
    f.a[4][1]=3,f.a[5][1]=1;
    size=5;
    matrix tmp1=ksm(cs,n-3)*f;
    ll ans=Ksm(c,tmp1.a[1][1]);

    size=3;
    memset(cs.a,0,sizeof(cs.a));
    cs.a[1][1]=cs.a[1][2]=cs.a[1][3]=cs.a[2][1]=cs.a[3][2]=1;
    matrix tmp2=ksm(cs,n-4);
    ans=ans*Ksm(f1,(ll)tmp2.a[1][3]+(ll)tmp2.a[2][3]+(ll)tmp2.a[3][3])%mod;
    ans=ans*Ksm(f2,(ll)tmp2.a[1][2]+(ll)tmp2.a[2][2]+(ll)tmp2.a[3][2])%mod;
    ans=ans*Ksm(f3,(ll)tmp2.a[1][1]+(ll)tmp2.a[2][1]+(ll)tmp2.a[3][1])%mod;
    printf("%lld\n",ans);
    return 0;
}