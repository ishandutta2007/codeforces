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
cll IO_res=IO(),T=readll();
void init(){
}
aN p,s,head,to,next,d;
ll cnt;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
ll f[N][2];
//aN g;
void dfs(cll u,cll fa,cll l){
    //g[u]=l;
    if(d[u]){
        cll s=l/d[u],r=l-s*d[u];
        ll sum=0,z[d[u]+1]={},t=0;
        rev(i,u,v)if(v^fa)dfs(v,u,s),z[t++]=f[v][1]-f[v][0],sum+=f[v][0];
        std::sort(z,z+t,std::greater<ll>());
        ref(i,0,r)sum+=z[i];
        f[u][0]=sum+::s[u]*l,f[u][1]=sum+z[r]+::s[u]*(l+1);
    }else f[u][0]=s[u]*l,f[u][1]=s[u]*(l+1);
}
void calc(){
    cll n=readll(),k=readll();
    memset(head,cnt=0,(n+1)<<3);
    memset(d,0,(n+1)<<3);
    rep(i,2,n)p[i]=readll(),++d[p[i]],add(p[i],i);
    rep(i,1,n)s[i]=readll();
    dfs(1,0,k);
    writell(f[1][0],10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}