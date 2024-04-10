#include<bits/stdc++.h>
#define maxn 50

using namespace std;
typedef long long ll;
ll n,m,p,q,x,y,r,a,b,e,f,t;

struct bignum{
    int a[maxn];
    int len;

    void print()
    {
        for (int i=len-1;i>=0;i--) printf("%d",a[i]); printf("\n");
    }

    void clearf()
    {
        for (int i=0;i<len;i++) a[i]=0;
        len=1;
    }

    bignum operator +(const bignum &b){
        bignum t;
        int l=max(len,b.len);
        if (l==len){
            for (int i=0;i<b.len;i++) t.a[i]=a[i]+b.a[i];
            for (int i=b.len;i<l;i++) t.a[i]=a[i];
        }
        else{
            for (int i=0;i<len;i++) t.a[i]=a[i]+b.a[i];
            for (int i=len;i<l;i++) t.a[i]=b.a[i];
        }
        t.a[l]=0;
        for (int i=0;i<l;i++)
        {
            t.a[i+1]+=t.a[i]/5;
            t.a[i]%=5;
        }
        t.len=l+(t.a[l]>0);
        return t;
    }

    bignum operator -(const bignum &b)
    {
        bignum t;
        int l=len;
        for (int i=0;i<b.len;i++) t.a[i]=a[i]-b.a[i];
        for (int i=b.len;i<l;i++) t.a[i]=a[i];
        for (int i=0;i<l;i++)
        {
            if (t.a[i]<0){
                t.a[i]+=5;t.a[i+1]--;
            }
        }
        while (l>1&&t.a[l-1]==0) l--;
        t.len=l;
        return t;
    }

    bignum operator *(const bignum &b)
    {
        bignum t;
        int l=len+b.len;
        for (int i=0;i<l;i++) t.a[i]=0;
        for (int i=0;i<len;i++)
            for (int j=0;j<b.len;j++)
                t.a[i+j]+=a[i]*b.a[j];
        for (int i=0;i<l;i++)
        {
            t.a[i+1]+=t.a[i]/5;
            t.a[i]%=5;
        }
        while (l>1&&t.a[l-1]==0) l--;
        t.len=l;
        return t;
    }

    bignum operator /(const int &b)
    {
        bignum t;
        int l=len;
        for (int i=0;i<l;i++) t.a[i]=0;
        int k=0;
        for (int i=len-1;i>=0;i--)
        {
            k=k*5+a[i];
            t.a[i]=k/b;
            k%=b;
        }
        while (l>1&&t.a[l-1]==0) l--;
        t.len=l;
        return t;
    }

    ll operator %(const ll &b)
    {
        ll k=0;
        for (int i=len-1;i>=0;i--)
        {
            k=k*5+a[i];
            k%=b;
        }
        return k;
    }

    bool operator <(const bignum &b)
    {
        if (len!=b.len) return len<b.len;
        for (int i=len-1;i>=0;i--) if (a[i]!=b.a[i]) return a[i]<b.a[i];
        return false;
    }
};

bignum get_bignum(ll x){
    bignum tmp;
    int r=0;
    while (x){
        tmp.a[r++]=x%5;
        x/=5;
    }
    tmp.len=r;
    return tmp;
}

ll phi(ll x){
    ll rt=x;
    for (ll j=2;j*j<=x;j++){
        if (x%j) continue;
        rt=rt/j*(j-1);
        while (x%j==0) x/=j;
    }
    if (x>1) rt=rt/x*(x-1);
    return rt;
}

ll pow_(ll x,ll y,ll z){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%z;
        y>>=1;
        x=x*x%z;
    }
    return rt;
}

ll gcd(ll x,ll y){
    if (x%y==0) return y;
    else return gcd(y,x%y);
}

ll solve(ll a,ll b,ll c,ll d){
    ll u=phi(b),v=phi(d);
    e=pow_(d,u-1,b);
    f=pow_(b,v-1,d);
    //cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;
    bignum o1,o2,o3,o4,o5,o6,rt;
    o1=get_bignum(a);
    o2=get_bignum(d);
    o3=get_bignum(e);
    o4=get_bignum(b);
    o5=get_bignum(c);
    o6=get_bignum(f);
    rt=o1*o2*o3+o4*o5*o6;
    return rt%(b*d);
}

int main()
{
    cin >> n >> m >> x >> y >> p >> q;
    if (p*q) {
        r=gcd(n,m);
        if ((p*x-q*y)%r) {
            cout << -1 << endl;
            return 0;
        }
        a=(p==1)?n-x:x;
        b=(q==1)?m-y:y;
        ll res=a%r;
        ll tmp=solve(a/r,n/r,b/r,m/r)*r+res;
        t=p*(tmp%(n*2))+x;
        x=t/n;
        t=q*(tmp%(m*2))+y;
        y=t/m;
        if (x&1) cout << n << ' '; else cout << 0 << ' ';
        if (y&1) cout << m << endl; else cout << 0 << endl;
    }
    else {
        if (p==1){
            if (y==0) cout << n << ' ' << 0 << endl;
            else if (y==m) cout << n << ' ' << m << endl;
            else cout << -1 << endl;
        }
        if (p==-1){
            if (y==0) cout << 0 << ' ' << 0 << endl;
            else if (y==m) cout << 0 << ' ' << m << endl;
            else cout << -1 << endl;
        }
        if (q==1){
            if (x==0) cout << 0 << ' ' << m << endl;
            else if (x==n) cout << n << ' ' << m << endl;
            else cout << -1 << endl;
        }
        if (q==-1){
            if (x==0) cout << 0 << ' ' << 0 << endl;
            else if (x==n) cout << n << ' ' << 0 << endl;
            else cout << -1 << endl;
        }
    }
}