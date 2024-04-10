#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(cll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
cll IO_res=IO(),T=readll();
#define $(x...)x
aN a,ift,ft;
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
} 
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return x<0?x+m:x;
}
void init(){
    cll n=1e6;
    ll x=ft[0]=1;
    rep(i,1,n)ft[i]=x=x*i%mod;
    x=inv(x);
    per(i,n,1)ift[i]=x,x=x*i%mod;
}
ll C(cll n,cll m){
    return m<0||m>n?0:ft[n]*ift[m]%mod*ift[n-m]%mod;
}
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    ll ans=1,l=0,r=n+1,ls=0,rs=0;
    if(l<r)ls+=::a[++l],rs+=::a[--r];
    while(l<r){
        while(l<r&&ls<rs)ls+=a[++l];
        while(l<r&&ls>rs)rs+=a[--r];
        if(l>=r)break;
        if(ls==rs){
            ll a=1,b=1;
            while(l+1<r&&::a[l+1]==0)a++,l++;
            while(l<r-1&&::a[r-1]==0)b++,r--;
            if(l==r-1)ans=ans*pow(2,a)%mod;
            else ans=ans*C(a+b,std::min(a,b))%mod;
            if(l<r)ls+=::a[++l],rs+=::a[--r];
        }
        if(l>=r)break;
    }
    writell(ans,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}