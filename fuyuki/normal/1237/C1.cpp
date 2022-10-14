#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
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
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=2e5+1,INF=0x7fffffff,K=3;
ll ans;
int n,m,rt,WD,tot,tag[N];
struct data{
	int sta[N],top,tot;
	I newnode(){return top?sta[top--]:++tot;}
	V del(rnt x){sta[++top]=x;}
}T;
struct mat{
    int mx[K][2];
    mat(){FOR(i,0,K-1)mx[i][0]=INF,mx[i][1]=-INF;}
};
struct poi{
    int x[K],id;
    V input(){FOR(i,0,K-1)x[i]=getint();}
    B operator<(const poi&u)const{return x[WD]<u.x[WD];}
    B operator==(const poi&u)const{
		FOR(i,0,K-1)if(x[i]!=u.x[i])return false;
		return true;
	}
}a[N],b[N],out;
int at[N];
struct kdt{
    mat pos;poi now;
    int ls,rs,liv,siz,fa;
}t[N];
#define lc t[p].ls
#define rc t[p].rs
V update(rnt p){
	t[p].siz=t[lc].siz+t[rc].siz+t[p].liv;
	FOR(i,0,K-1)t[p].pos.mx[i][1]=max(t[lc].pos.mx[i][1],t[rc].pos.mx[i][1]);
	FOR(i,0,K-1)t[p].pos.mx[i][0]=min(t[lc].pos.mx[i][0],t[rc].pos.mx[i][0]);
	if(t[p].liv){
		FOR(i,0,K-1)t[p].pos.mx[i][0]=min(t[p].now.x[i],t[p].pos.mx[i][0]);
		FOR(i,0,K-1)t[p].pos.mx[i][1]=max(t[p].now.x[i],t[p].pos.mx[i][1]);
	}
}
V build(int&p,rnt L,rnt R,rnt wd){
    if(L>R)return;rnt mid=L+R>>1;
    p=++tot,WD=wd,nth_element(a+L,a+mid,a+R+1);
    build(lc,L,mid-1,(wd+1)%K),build(rc,mid+1,R,(wd+1)%K);
    t[p].now=a[mid],t[p].liv=1,update(p);
    t[lc].fa=p,t[rc].fa=p,at[a[mid].id]=p;
}
V del(rnt p){
	p=at[p],t[p].liv=0;
	while(p)update(p),p=t[p].fa;
}
LL pw(rnt x){return 1ll*x*x;}
LL calc(const poi&x,const poi&y){
	ll out=0;
	FOR(i,0,K-1)out+=pw(x.x[i]-y.x[i]);
	return out;
}
LL dis(const poi&x,const mat&y){
	re ll out=0;
	FOR(i,0,K-1)out+=pw(max(0,y.mx[i][0]-x.x[i])+max(0,x.x[i]-y.mx[i][1]));
	return out;
}
V ask(rnt p,const poi&x){
    if(!p||!t[p].siz)return;
    if(t[p].liv){
    	ll u=calc(x,t[p].now);
    	if(u<ans)ans=u,out=t[p].now;
	}
    rnt lval=dis(x,t[lc].pos),rval=dis(x,t[rc].pos);
    if(lval<rval){
        if(lval<ans)ask(lc,x);
        if(rval<ans)ask(rc,x);
    }else{
        if(rval<ans)ask(rc,x);
        if(lval<ans)ask(lc,x);
    }
}
V input(){n=getint();FOR(i,1,n)a[i].input(),a[i].id=i,b[i]=a[i];}
V work(){
	build(rt,1,n,0);
	FOR(i,1,n)if(!tag[i]){
		ans=1ll<<62;
		del(i);
		ask(rt,b[i]);
		cout<<i<<' '<<out.id<<'\n';
		tag[out.id]=1;
		del(out.id);
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}