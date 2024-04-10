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
cll N=2e6+7,mod=998244353,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
#define $y(x...)x
cll IO_res=IO(),T=1;
void init(){
}
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
aN a,head,to,next,w,dis,end,hz;
ll cnt=0;
void add(cll u,cll v,cll c){
    //printf("%lld %lld %lld\n",u,v,c);
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
struct node{
    ll u,dis;
    operator ll()const{
        return-dis;
    }
    int check()const{
        return ::dis[u]==dis;
    }
};
std::priority_queue<node>qu;
ll m,p,q;
ll getdis(cll u,cll v){
    if(v==0)return 0;
    cll d=(u-1)/m==(v-1)/m,e=(u-1)%m==(v-1)%m,z=d+e;
    return z==0?p:z==1?q:0;
}
void calc(){
    cll n=readll();
    m=readll(),p=readll(),q=readll();
    rep(i,1,n*m)a[i]=readchar();
    ll cnt=0;
    rep(i,1,n)rep(j,1,m){
        cll u=++cnt;
        if(a[u]=='L')hz[u]=u+1;
        if(a[u]=='R')hz[u]=u-1;
        if(a[u]=='U')hz[u]=u+m;
        if(a[u]=='D')hz[u]=u-m;
    }
    memset(dis,0x3f,sizeof dis);
    ll ans=dis[0];
    cnt=0;
    rep(i,1,n)rep(j,1,m){
        cll u=++cnt;
        if(a[u]=='.'){
            if((i^j)&1)dis[u]=0,qu.push((node){u,dis[u]});
            else end[u]=1;
        }
        if(i!=1){//up
#define zh(x,y)(((x+0)-1)*m+(y+0))
            cll v=zh(i-1,j);
            if((i^j)&1)add(u,v,0);
            ll x=u,y=hz[v],w=getdis(x,y);
            if(!((i^j)&1))std::swap(x,y);
            if(w)add(x,y,w);
        }
        if(j!=1){//left
            cll v=zh(i,j-1);
            if((i^j)&1)add(u,v,0);
            ll x=u,y=hz[v],w=getdis(x,y);
            if(!((i^j)&1))std::swap(x,y);
            if(w)add(x,y,w);
        }
        if(i!=n){//down
            cll v=zh(i+1,j);
            if((i^j)&1)add(u,v,0);
            ll x=u,y=hz[v],w=getdis(x,y);
            //printf("%lld %lld \n",x,y);
            if(!((i^j)&1))std::swap(x,y);
            if(w)add(x,y,w);
        }
        if(j!=m){//right
            cll v=zh(i,j+1);
            if((i^j)&1)add(u,v,0);
            ll x=u,y=hz[v],w=getdis(x,y);
            if(!((i^j)&1))std::swap(x,y);
            if(w)add(x,y,w);
        }
        //puts("????");
    }
    while(!qu.empty()){
        cll u=qu.top().u;
        qu.pop();
        if(end[u]){
            ans=dis[u];
            break;
        }
        rev(i,u,v)if(dis[v]>dis[u]+w[i])dis[v]=dis[u]+w[i],qu.push((node){v,dis[v]});
        while(!qu.empty()&&!qu.top().check())qu.pop();
    }
    //rep(i,1,n*m)if(end[i])ans=std::min(dis[i],ans);
    writell(ans>mod*mod?-1:ans,10);
}
int main(){
    init();
    rep(i,1,T)calc();
    return 0;
}