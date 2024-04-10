#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MOD=1e9+6;
const LL mod=1e9+7;
struct tu
{
    LL a,b,c,d;
    tu(){a=b=c=d=0;}
    tu(LL a):a(a){b=c=d=a;}
    tu(LL a,LL b,LL c,LL d):a(a),b(b),c(c),d(d){}
    inline tu operator*(const tu&x)
    {
        return tu((a*x.a)%MOD,(b*x.b)%MOD,(c*x.c)%MOD,(d*x.d)%MOD);
    }
    inline tu operator+(const tu&x)
    {
        return tu((a+x.a)%MOD,(b+x.b)%MOD,(c+x.c)%MOD,(d+x.d)%MOD);
    }
};
struct Mt
{
    LL r,c;
    vector<vector<tu> >V;
    Mt(){}
    Mt(LL r):r(r),c(r)
    {
        V.assign(r,vector<tu>(r));
        for(LL i=0;i<r;i++)
            V[i][i]=tu(1);
    }
    Mt(LL r,LL c):r(r),c(c){V.assign(r,vector<tu>(c));}
    inline Mt operator*(const Mt&x)
    {
        Mt ret(r,x.c);
        if(c!=x.r)
            return ret;
        LL i,j,k;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                for(k=0;k<x.c;k++)
                    ret.V[i][k]=ret.V[i][k]+V[i][j]*x.V[j][k];
        return ret;
    }
};
inline Mt Pow(Mt x,LL y)
{
    Mt ret(x.r);
    while(y>0)
    {
        if(y&1)
            ret=ret*x;
        x=x*x;
        y>>=1;
    }
    return ret;
}
inline LL Pow(LL x,LL y)
{
    LL ret=1;
    while(y>0)
    {
        if(y&1)
            ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
Mt MM(5,5);
LL N,f1,f2,f3,c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    MM.V[0]=vector<tu>({tu(1),tu(0),tu(0),tu(0),tu(0)});
    MM.V[1]=vector<tu>({tu(1),tu(1),tu(0),tu(0),tu(0)});
    MM.V[2]=vector<tu>({tu(0),tu(1),tu(1),tu(1),tu(1)});
    MM.V[3]=vector<tu>({tu(0),tu(0),tu(1),tu(0),tu(0)});
    MM.V[4]=vector<tu>({tu(0),tu(0),tu(0),tu(1),tu(0)});
    Mt D=Pow(MM,N-3);
    cin>>f1>>f2>>f3>>c;
    Mt P(5,1);
    P.V[0][0]=tu(2,0,0,0);
    P.V[1][0]=tu(2,0,0,0);
    P.V[2][0]=tu(0,1,0,0);
    P.V[3][0]=tu(0,0,1,0);
    P.V[4][0]=tu(0,0,0,1);
    Mt rans=D*P;
    tu t=rans.V[2][0];
    LL ans=Pow(c,t.a);
    ans=ans*Pow(f3,t.b)%mod;
    ans=ans*Pow(f2,t.c)%mod;
    ans=ans*Pow(f1,t.d)%mod;
    cout<<ans<<endl;
    return 0;
}