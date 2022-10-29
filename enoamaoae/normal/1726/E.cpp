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
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
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
ll inv(ll a,ll b=mod){
    ll x=1,y=0;
    cll m=b;
    while(b){
        cll t=a/b,lb=b,ly=y;
        b=a-t*b,a=lb,y=x-t*y,x=ly;
    }
    return x<0?x+m:x;
}
ll pow(ll a,cll b,cll p=mod){
    ll res=1;
    red(i,b){
        if(i&1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}
namespace mypoly{
    namespace inside{
        typedef ull ll,aN[1<<21|3143];
        typedef const ll cll;
        aN r,w,a,b,c,d,e,q,iv;
        void init(cll z){
            cll n=z<<1,h=pow(g,(mod-1)/n);
            rfor(ll*i=w+z,x=1;i!=w+n;)*i++=x,x=x*h%mod;
            rfor(ll*i=r+z,*j=r+z;i!=r+n;)*i++=*j>>1,*i++=(z|*j++)>>1;
            rfor(ll*i=w+z-1,*j=w+n-2;i!=w;)*i--=*j--,j--;
            rfor(ll*i=r+z-1,*j=r+n-2;i!=r;)*i--=*j--,j--;
            ll x=1;
            rfor(ll*i=iv+1,j=1;i!=iv+n+1;)*i++=x,x=j++*x%mod;
            x=inv(x);
            rfor(ll*i=iv+n,j=n;i!=iv;)*i=x**i%mod,i--,x=j--*x%mod;
        }
        void ntt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i!=n;i<<=1)rfor(ll*j=a;j!=a+n;j+=i<<1)
            rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*y**z++%mod,*y++=mod-t+*x,*x+++=t;
            rfor(ll*i=t,*j=a;i!=t+n;)*i++=*j++%mod;
        }
        void itt(ll*t,cll*s,cll n){
            rfor(cll*i=r+n,*j=s;j!=s+n;)a[*i++]=*j++;
            rfor(ll i=1;i!=n;i<<=1)rfor(ll*j=a;j!=a+n;j+=i<<1)
            rfor(ll*x=j,*y=j+i,*z=w+i,t;x!=j+i;)t=*y**z++%mod,*y++=mod-t+*x,*x+++=t;
            cll mul=mod-(mod-1)/n;
            a[n]=a[0];
            rfor(ll*i=t,*j=a+n;i!=t+n;)*i++=mul**j--%mod;
        }
        void set(ll*a,cll m,cll n){
            memset(a+m,0,(n-m)<<3);
        }
        void cpy(ll*a,cll*b,cll n){
            memcpy(a,b,n<<3);
        }
        void fix(ll*a,ll*b,cll m){
            cpy(a+m,b+m,m),cpy(b,a,m);
        }
        void exp(ll*t,cll*s,cll z){
            //F_1=(F_0*int((der(A)F_0-F_0')*inv(F_0)))_1
            //=(F_0*int(der(A)(F_0*inv(F_0)-1)+der(A)-F_0'*inv(F_0)))_1
            //=(F_0*(A-A_0+int((der(A_0)F_0*inv(F_0)-F_0')*inv(F_0))))_1
            set(e,0,z);
            set(q,0,z);
            *e=*q=*c=1;
            //a:ntt used
            //b:calc
            //c:temp
            //d:temp
            //e:F
            //q:inv(F)
            rfor(ll m=1;m!=z;m<<=1){
                cll n=m<<1 ;
                ref(i,0,m) b[i]=s[i]*i%mod;
                ntt(b,b,m) ;
                ref(i,0,m) b[i]=b[i]*c[i]%mod;
                itt(b,b,m) ;
                ref(i,0,m) b[i+m]=(b[i]+(mod-i)*e[i])%mod;
                set(b,0,m) ;//get b=der(A_0)F_0*inv(F_0)-F_0'
                ntt(b,b,n) ;
                ntt(d,q,n) ;
                ref(i,0,n) b[i]=b[i]*d[i]%mod;
                itt(b,b,n) ;
                ref(i,m,n) b[i]=(b[i]*iv[i]+s[i])%mod;
                set(b,0,m) ;//get b=(A-A_0+int((der(A_0)F_0*inv(F_0)-F_0')*inv(F_0)))_1
                ntt(b,b,n) ;
                ntt(c,e,n) ;
                ref(i,0,n) b[i]=b[i]*c[i]%mod;
                itt(b,b,n) ;
                fix(e,b,m) ;
                if(m*2==z) return cpy(t,e,z);
                ntt(c,e,n) ;
                ref(i,0,n) b[i]=c[i]*d[i]%mod;
                itt(b,b,n) ;
                set(b,0,m) ;
                ntt(b,b,n) ;
                ref(i,0,n) b[i]=mod-d[i]*b[i]%mod;
                itt(b,b,n) ;
                fix(q,b,m) ;
            }
        }
    }
    using inside::init;
    using inside::ntt;
    using inside::itt;
};
aN z,l,ift,ft;
ll C(ll n,ll m){
    return m<0||m>n?0:ft[n]*ift[m]%mod*ift[n-m]%mod;
}
void calc(){
    //writell(z[readll()],10);
    cll n=readll();
    ll ans=0,x=1;
    rep(i,0,n/2)if(~i&1)ans=(ans+C(n-i,i)*z[i]%mod*l[n-i*2]%mod*x%mod)%mod,x=x*2%mod;
    writell(ans,10);
    /*ll p[22];
    rep(i,1,n)p[i]=i;
    ll cnt=0;
    do{
        ll flag=1;
        rep(i,1,n)if((i-p[p[i]])*(i-p[p[i]])>1)flag=0;
        if(flag){
            cnt++;
            rep(i,1,n)writell(p[i],i==n?10:32);
        }
    }while(std::next_permutation(p+1,p+n+1));
    writell(cnt,10);*/
}
void init(){
    static mypoly::inside::aN f,g;
    mypoly::init(1<<20);
    ll x=ft[0]=1;
    cll n=1e6;
    rep(i,1,n)ft[i]=x=x*i%mod;
    x=inv(x);
    per(i,n,0)ift[i]=x,x=x*i%mod;
    x=1;
    rep(i,0,n/2)if(~i&1)f[i]=z[i]=C(i,i/2)*ft[i/2]%mod*x%mod,f[i]=f[i]*ift[i]%mod,x=x*iv2%mod;
    rep(i,0,n/2)g[i]=ift[i]%mod;
    cll z=2<<(31^__builtin_clz(n));
    mypoly::ntt(f,f,z);
    mypoly::ntt(g,g,z);
    ref(i,0,z)f[i]=f[i]*g[i]%mod;
    mypoly::itt(f,f,z);
    rep(i,0,n/2)l[i]=ft[i]*f[i]%mod;
    //rep(i,0,10)writell(::z[i]),writell(l[i],10); 
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}