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
cll N=1.2e6+7,mod=998244353,iv2=(mod+1)/2,iz=1<<21,oz=1<<22;
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
ull f[64][2][2],g[64][2][2];
void calc(){
    cll n=readll(),m=readll()-1;
    /*ll sum=0;
    rep(i,0,m)sum+=__builtin_parity(i^(i+n));
    writell(sum,10);*/
    f[0][0][0]=1,g[0][0][0]=1;
    rep(i,0,62){
        rep(j,0,1)rep(k,0,1)rep(l,0,1){
            cll s=(j+l+(n>>i&1)),a=s>>1,b=s&1;
            g[i+1][a][b^k^l]+=g[i][j][k];
        }
        rep(j,0,1)rep(k,0,1)rep(l,0,1){
            cll s=(j+l+(n>>i&1)),a=s>>1,b=s&1;
            if(l<(m>>i&1))f[i+1][a][b^k^l]+=g[i][j][k];
            if(l==(m>>i&1))f[i+1][a][b^k^l]+=f[i][j][k];
            //if(l==1)printf("%lld %lld %lld %lld %lld\n",i,j,k,f[i][j][k],g[i][j][k]);
        }
        /*if(n>>i&1){
        }else{
            g[i+1][0][0]=g[i][0][0]+g[i][1][1]+g[i][0][0];
            g[i+1][0][1]=g[i][1][0]+g[i][0][1]+g[i][0][0];
            g[i+1][1][0]=g[i][1][1];
            g[i+1][1][1]=g[i][1][0];
        }
        if(m>>i&1){//1
            
        }else{//0
        }*/
        memset(f[i],0,sizeof f[i]);
        memset(g[i],0,sizeof g[i]);
    }
    writell(f[63][0][1],10);
    memset(f[63],0,sizeof f[63]);
    memset(g[63],0,sizeof g[63]);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}