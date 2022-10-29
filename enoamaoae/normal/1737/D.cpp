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
#define $1(x...)
cll IO_res=IO(),T=readll();
void init(){
}
/*aN next,to,head,w,dis,min;
ll cnt;
void add(cll u,cll v,cll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
struct node{
    ll u,d;
    operator ll()const{
        return-d;
    }
    int check()const{
        return dis[u]==d;
    }
};
std::priority_queue<node>qu;*/
ll e[555][555],f[555][555];//,dp[555][;
void calc(){
    cll n=readll(),m=readll();
    memset(e,0x3f,sizeof e);
    memcpy(f,e,sizeof e);
    rep(i,1,n)f[i][i]=0;
    rep(i,1,m){
        cll u=readll(),v=readll(),w=readll();
        e[u][v]=std::min(e[u][v],w);
        e[v][u]=std::min(e[v][u],w);
        f[u][v]=1,f[v][u]=1;
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
    ll sum=mod*mod;
    //exit(0);
    rep(i,1,n)rep(j,1,n)if(e[i][j]<=1e9&&f[1][i]<=1e9){
        sum=std::min(sum,(f[1][i]+f[n][j]+1)*e[i][j]);
        rep(k,1,n)if(f[1][k]<=1e9)sum=std::min(sum,(f[1][k]+f[n][k]+2+f[k][i])*e[i][j]);
    }
    writell(sum,10);
    /*cll n=readll(),m=readll();
    memset(head,cnt=0,(n+1)<<3);
    memset(min,0x3f,(n+1)<<3);
    rep(i,1,m){
        cll u=readll(),v=readll(),w=readll();
        add(u,v,w);
        min[u]=std::min(min[u],w);
        min[v]=std::min(min[v],w);
    }
    memset(dis,0x3f,(n+1)<<3),dis[1]=0;
    qu.push((node){1,dis[1]});
    //ll sum=mod*mod;
    while(!qu.empty()){
        cll u=qu.top().u;
        qu.pop();
        //ll min=mod*mod;
        rev(i,u,v){
            if(dis[v]>dis[u]+min[u])dis[v]=dis[u]+min[u],qu.push((node){v,dis[v]});
            //min=std::min(min,w[i]);
        }
        //sum=std::min(sum,dis[u]+min*2);
        while(!qu.empty()&&!qu.top().check())qu.pop();
    }
    //sum=std::min(sum,dis[n]);
    writell(dis[n],10);*/
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}