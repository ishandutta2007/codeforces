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
cll N=1e6+7,mod=1e18+7,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO();
//cll T=100000;
cll T=readll();
aN head,to,next,w,f,ans,gz,dfn;
ll cnt,top;
void add(cll u,cll v,cll id){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=id;
}
ll t,tu;
ll st[5],su[9];
ll cases=0;
void dfs(cll u,cll fa){
    if(cases==235)printf("%lld == %lld\n",u,fa); 
    dfn[u]=++top;
    rev(i,u,v)if(!dfn[v])f[v]=w[i],gz[w[i]]=1,dfs(v,u);
    else if(v!=fa&&dfn[v]>dfn[u])st[++t]=w[i],su[++tu]=u,su[++tu]=v;//,printf("u=%lld v=%lld\n",u,v);
}
ll cmp(ll a,ll b){
    return dfn[a]<dfn[b];
}
aN fd,gu,gv;
ll find(cll u){
    return u^fd[u]?fd[u]=find(fd[u]):u;
}
ll map[19][19];
void calc(){
    //cll n=rand()%10+1,m=std::min(n*(n-1)/2,n-1+rand()%4);
    cll n=readll(),m=readll();
    memset(head,cnt=top=t=tu=0,(n+1)<<3);
    memset(dfn,0,(n+1)<<3);
    memset(ans,0,(m+1)<<3);
    memset(gz,0,(m+1)<<3);
    memset(map,0,sizeof map);
    //rep(i,1,n)fd[i]=i;
    //writell(cases,10);
    //if(cases==235)writell(find(10)),writell(find(1));
    /*rep(i,1,m){
        ll u,v;
        do u=rand()%n+1,v=rand()%n+1;
        while(map[u][v]||u==v);
        gu[i]=u,gv[i]=v;
        map[u][v]=map[v][u]=1;
        add(u,v,i),add(v,u,i);
        //printf("u=%lld v=%lld %lld %lld\n",u,v,gu[i],gv[i]);
        fd[find(u)]=find(v);
    }*/
    rep(i,1,m){
        cll u=readll(),v=readll();
        add(u,v,i),add(v,u,i);
    }
    //rep(i,2,n)if(find(i)!=find(1))return;
    if(cases==235)writell(n),writell(m,10);
    if(cases==235)rep(i,1,m)writell(gu[i]),writell(gv[i],10);
    dfs(1,0);
    ll flag=0;
    if(t==3){
        std::sort(su+1,su+tu+1,cmp);
        cll n=std::unique(su+1,su+tu+1)-su-1;
        if(n==3){
            //printf("???");
            cll z=su[2];
            //printf("%lld %lld %lld\n",dfn[1],dfn[7],dfn[3]);
            rev(i,z,v)if(w[i]==f[z]||gz[w[i]]==0)ans[w[i]]=1,static_cast<void>(v);
            flag=1;
        }
    }
    if(!flag)rep(i,1,t)ans[st[i]]=1;
    rep(i,1,m)writell(ans[i],i==m?10:0);
    /*rep(i,1,n)fd[i]=i;
    rep(i,1,m)if(ans[i]==0)assert(find(gu[i])!=find(gv[i])),fd[find(gu[i])]=find(gv[i]);
    rep(i,1,n)fd[i]=i;
    rep(i,1,m)if(ans[i]==1)assert(find(gu[i])!=find(gv[i])),fd[find(gu[i])]=find(gv[i]);*/
}
void init(){
}
int main(){
    init();
    rep(i,1,T)cases=-i,calc();
    return 0;
}