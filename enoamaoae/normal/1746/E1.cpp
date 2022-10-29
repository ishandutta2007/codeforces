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
#define $1(x...)x
#define $2(x...)x
cll IO_res=(IO(),gc=getchar,0),T=1;
void init(){
}
aN a;
char s[126];
/*ll query(cll w,cll*g,cll n){
    ll t=0;
    pc('?'),pc(' ');
    rep(i,1,n)if(i>>w&1)a[++t]=i;
    writell(t);
    rep(i,1,t)writell(g[a[i]],t==i?10:32);
    fout(),fflush(stdout);
    mygets(s);
    return s[0]=='Y';
}*/
ll n;
ll getans(cll u){
    if(u>n||u<1)return 0; 
    pc('!'),pc(' '),writell(u,10);
    fout(),fflush(stdout);
    mygets(s);
    return s[1]==')';
}
ll query(cll w,cll n){
    ll t=0;
    rep(i,1,n)if(i>>w&1)a[++t]=i;
    if(t==0)return 0;
    pc('?'),pc(' ');
    writell(t);
    rep(i,1,t)writell(a[i],t==i?10:32);
    fout(),fflush(stdout);
    mygets(s);
    return s[0]=='Y';
}
ll query2(cll z,cll w,cll n){
    ll t=0;
    rep(i,1,n)if((i&((1<<w)-1))==z)a[++t]=i;
    if(t==0)return 0;
    pc('?'),pc(' ');
    writell(t);
    rep(i,1,t)writell(a[i],t==i?10:32);
    fout(),fflush(stdout);
    mygets(s);
    return s[0]=='Y';
}
void calc(){
    cll n=::n=readll();
    ll a=0,b=1;
    rep(i,1,16){
        cll x=query(i,n),z=query2(a,i,n),w=query2(a,i,n),t=query(i,n);
        cll d=t<<i,bs=z?a:b,c=w?a:b,as=x<<i;
        if(z==w)z?b=a|1<<i:a=b|1<<i;
        else a=d|bs,b=as|c;
    }
    getans(a)||getans(b);
    /*ll t=0;
    rep(i,1,n){
        if(i&(i>>1))++t;
        f[i]=f[i-t]+1;
    }
    writell(t,10);
    writell(f[n],10);*/
    /*ll a=0,b=0,lst=0,lstx=0,lsty=0;
    rep(i,0,17){
        cll x=query(i),y=query(i);
        if(x==y){
            a|=x<<i;
            if(lst){
                cll z=query(lst);
                if(z)
            }
        }else b|=x<<i,lst=i,lstx=x,lsty=y; 
    }
    assert(getans(a)||getans(a^b));*/
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}