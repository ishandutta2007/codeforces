#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1.2e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
aN a,b,f;
void calc(){
    cll n=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,n)b[i]=readll();
    ll ans=0;
    per(i,29,0){
        ll lst=1;
        rep(j,1,n)if(j==n||((a[j]^a[j+1])>>i>>1)){
            //printf("%lld ~ %lld\n",lst,j);
            ll t=lst-1;
            rep(k,lst,j)if(!(a[k]>>i&1))f[++t]=a[k];
            rep(k,lst,j)if(a[k]>>i&1)f[++t]=a[k];
            assert(t==j);
            memcpy(a+lst,f+lst,(j-lst+1)<<3);
            lst=j+1;
        }
        lst=1;
        rep(j,1,n)if(j==n||((b[j]^b[j+1])>>i>>1)){
            ll t=lst-1;
            rep(k,lst,j)if(b[k]>>i&1)f[++t]=b[k];
            rep(k,lst,j)if(!(b[k]>>i&1))f[++t]=b[k];
            assert(t==j);
            memcpy(b+lst,f+lst,(j-lst+1)<<3);
            lst=j+1;
        }
        //rep(j,1,n)writell(a[j],j==n?10:32);
        //rep(j,1,n)writell(b[j],j==n?10:32);
        ll flag=1;
        rep(j,1,n)if(!((a[j]^b[j])>>i&1)){flag=0;break;}
        if(!flag)rep(j,1,n)a[j]&=~(1<<i),b[j]&=~(1<<i);
        else ans|=1<<i;
    }
    writell(ans,10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
1
2
0 1
0 1
*/