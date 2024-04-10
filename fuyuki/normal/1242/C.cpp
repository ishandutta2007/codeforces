#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define fs first
#define sc second
#define rnt re int
#define re register
#define I inline int
#define mk make_pair
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    static const int flag[2]={1,-1};
    rnt _s=0,_f=1;re char _ch=gc;
    while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s*_f;
}
const int N=16;
int n,m,S,sta,bk[N];
ll s[N],sum;
map<ll,int>mp;
V input(){
    n=getint();
    FOR(i,1,n){
        m=getint();rnt x;
        while(m--)x=getint(),s[i]+=x,sum+=x,mp[x]=i;
    }
}
struct node{
    int w[N],t[N],tag;
    V init(){memset(w,0,sizeof(w)),memset(t,0,sizeof(t)),tag=0;}
    V output(){FOR(i,1,n)cout<<w[i]<<' '<<t[i]<<'\n';}
    node operator+(const node&u)const{
        static node out;out.tag=1;
        FOR(i,1,n)out.w[i]=w[i]|u.w[i];
        FOR(i,1,n)out.t[i]=t[i]|u.t[i];
        return out;
    }
}dp[1<<N],tmp;
V dfs(rnt p,rnt x){
    if(bk[p]){
        if(p!=sta)return;
        x=0,tmp.tag=1;
        FOR(i,1,n)x|=bk[i]<<i-1;
        dp[x]=tmp;
        return;
    }
    ll now=sum-s[p]+x;
    bk[p]=1,tmp.w[p]=x;
    if(!sta)sta=p;
    if(mp.find(now)!=mp.end()){
        x=mp[now];
        if(bk[x]&&tmp.w[x]!=now)return;
        tmp.t[x]=p,tmp.w[x]=now,dfs(x,now);
    }
}
V init(){memset(bk,0,sizeof(bk)),sta=0,tmp.init();}
V work(){
    if(sum%n)return void(cout<<"No");sum/=n,S=1<<n,S--;
    for(P x:mp)init(),dfs(x.sc,x.fs);
    FOR(i,0,S)if(!dp[i].tag)for(rnt j=i;j;j=(j-1)&i)if(dp[j].tag&&dp[i^j].tag){
        dp[i]=dp[j]+dp[i^j];break;
    }
    if(dp[S].tag)cout<<"Yes\n",dp[S].output();
    else cout<<"No";
}
int main(){
    input();
    work();
    return 0;
}