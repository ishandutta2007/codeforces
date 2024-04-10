#include <iostream>
#include <vector>
#include <string>

#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

int mod=1000000007;

int mPow(int x,int a)
{
    int res=1;
    while(x)
    {
        if (x&1) res=(1LL*res*a)%mod;
        a=(1LL*a*a)%mod; x>>=1;
    }
    return res;
}

struct matrix{
    matrix() { memset(a,0,sizeof(a)); };
    int a[16][16];
    void make_one()
    {
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                a[i][j]=(i==j);
    }
    void out()
    {
        for(int i=0;i<16;i++)
        {
            for(int j=0;j<16;j++)
                cout << a[i][j] << "    ";
            cout << endl;
        }
    }
    int calc()
    {
        int res=0;
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                res=(res+a[i][j])%mod;
        return res;
    }
};

matrix operator * (const matrix & a,const matrix & b)
{
    matrix r;
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            for(int t=0;t<16;t++)
                r.a[i][j]=(r.a[i][j]+1LL*a.a[i][t]*b.a[t][j])%mod;
    return r;
}

matrix operator + (const matrix & a,const matrix & b)
{
    matrix r;
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            r.a[i][j]=(a.a[i][j]+b.a[i][j])%mod;
    return r;
}

matrix operator - (const matrix & a,const matrix & b)
{
    matrix r;
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            r.a[i][j]=(a.a[i][j]-b.a[i][j]+mod)%mod;
    return r;
}

char lett[]="WYRB";
// WY RB BWR RWB

matrix construct()
{
    matrix r;
    for(int f=0;f<16;f++)
    {
        if ((f>>2)==0&&(f&3)==1||(f>>2)==1&&(f&3)==0||
            (f>>2)==2&&(f&3)==3||(f>>2)==3&&(f&3)==2) continue;
        for(int s=0;s<16;s++)
        {
            r.a[f][s]=1;
            if ((f&3)==(f>>2)||
                (f&3)==(s&3)||(f&3)==0&&(s&3)==1||(f&3)==1&&(s&3)==0||
                (f&3)==2&&(s&3)==3||(f&3)==3&&(s&3)==2||(f&3)!=(s>>2)||
                (f>>2)==2&&(f&3)==0&&(s&3)==3||(f>>2)==3&&(f&3)==0&&(s&3)==2) r.a[f][s]=0;
        }
    }
    return r;
}

matrix mPow(int x,matrix a)
{
    matrix r;
    r.make_one();
    while(x)
    {
        if (x&1) r=r*a;
        a=a*a; x>>=1;
    }
    return r;
}

matrix geom(matrix a,int n)
{
    matrix c;
    if (n==0) return c;
    if (n==1)
    {
        c=construct();
        return c;
    }
    c=mPow(n/2,construct());
    matrix s=geom(a,n>>1);
    matrix res=s*c;
    if (n&1) res=res+mPow(n,construct());
    return res+s;
}

int count_pal(int n)
{
    matrix r;
    if (n>3)
        r=geom(construct(),(n-3)>>1);
    int ret=r.calc();
    if (3<=n) ret=(ret+8)%mod;
    return ret;
}

int get(int n)
{
    if (n==0) return 0;
    if (n==1) return 4;
    if (n==2) return 8;
    matrix r=geom(construct(),n-2);
    int res=(r.calc()+count_pal(n)+16)%mod;
    res=(1LL*res*mPow(mod-2,2))%mod;
    return res;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int l,r;
    cin >> l >> r;
//  cout << get(r) << " " << get(l-1) << endl;
    cout << (get(r)-get(l-1)+mod)%mod << endl;
    return 0;
}