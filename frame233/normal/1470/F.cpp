#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005,inf=0x3f3f3f3f,MX=1000000000,NC=(1<<19)+5;typedef long long ll;
struct node{int x,y;inline bool operator < (const node &o)const{return x<o.x;}}a[N];int n;
inline bool cmpy(const node &x,const node &y){return x.y<y.y;}
struct seg{int a,b;inline int get()const{return std::max(0,b-a);}};
inline seg merge(const seg &a,const seg &b){return {std::min(a.a,b.a),std::max(a.b,b.b)};}
struct rect{int a,b,c,d;inline ll get()const{return 1LL*std::max(0,b-a)*std::max(0,d-c);}}pre[N],suf[N];
inline rect merge(const rect &a,const rect &b){return {std::min(a.a,b.a),std::max(a.b,b.b),std::min(a.c,b.c),std::max(a.d,b.d)};}
int t[N],pos,yy[N];
ll solve1(){
	ll ans=1e18;
	for(int t=0;t<2;++t){
		std::sort(a+1,a+n+1);
		pre[0]={inf,-inf,inf,-inf};for(int i=1;i<=n;++i)pre[i]=merge(pre[i-1],{a[i].x,a[i].x,a[i].y,a[i].y});
		suf[n+1]={inf,-inf,inf,-inf};for(int i=n;i>=1;--i)suf[i]=merge(suf[i+1],{a[i].x,a[i].x,a[i].y,a[i].y});
		for(int i=1;i<n;++i)ans=std::min(ans,pre[i].get()+suf[i+1].get());
		for(int i=1;i<=n;++i)std::swap(a[i].x,a[i].y);
	}
	return ans;
}
struct qry{int x,y,op;inline bool operator < (const qry &o)const{return x==o.x?op==o.op?y<o.y:op<o.op:x<o.x;}}q[N*2];int p;
int pool[N*21],*P=pool;rect all;
inline int X(int i){return -(all.b-q[i].x);}
inline int Y(int i){return q[i].y-all.c;}
inline ll cross(int x1,int y1,int x2,int y2){return 1LL*x1*y2-1LL*y1*x2;}
inline ll calc(int id,int a,int c){return 1LL*a*(q[id].y-all.c)+1LL*c*(all.b-q[id].x);}
struct HULL{
	int *st,top;
	void init(int n){st=P,top=-1,P+=n;}
	void push(int i){
		while(top+1>=2&&cross(X(i)-X(st[top-1]),Y(i)-Y(st[top-1]),X(st[top])-X(st[top-1]),Y(st[top])-Y(st[top-1]))>=0)--top;
		st[++top]=i;
	}
	ll ask(int a,int c){
		if(top==-1)return 1e18;
		while(top+1>=2&&calc(st[top-1],a,c)<=calc(st[top],a,c))--top;
		return calc(st[top],a,c);
	}
}f[NC];int M,len[NC],cnt[N];
void build(int n){
	P=pool;for(M=1;M<=n+2;M<<=1);
	memset(len,0,(M+M+3)*4);
	for(int i=1;i<=n;++i)len[i+M]=cnt[i],f[i+M].init(len[i+M]);
	for(int i=M-1;i>=1;--i)len[i]=len[i<<1]+len[i<<1|1],f[i].init(len[i]);
}
void upd(int x,int id){for(x+=M;x;x>>=1)f[x].push(id);}
ll ask(int s,int t,int a,int c){
	ll ans=1e18;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=std::min(ans,f[s^1].ask(a,c));
		if(t&1)ans=std::min(ans,f[t^1].ask(a,c));
	}
	return ans;
}
ll solve2(){
	ll ans=1e18;
	for(int st=0;st<4;++st){
		if(st&1)for(int i=1;i<=n;++i)a[i].x=MX-a[i].x;
		if(st&2)for(int i=1;i<=n;++i)a[i].y=MX-a[i].y;
		pos=0;for(int i=1;i<=n;++i)t[++pos]=a[i].y;
		std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
		all={inf,-inf,inf,-inf};for(int i=1;i<=n;++i)all=merge(all,{a[i].x,a[i].x,a[i].y,a[i].y});
		memset(cnt,0,(pos+3)<<2);
		std::sort(a+1,a+n+1,cmpy);p=0;
		for(int i=n,xm=inf;i>=1;--i){
			if(xm<inf)q[++p]={xm,a[i].y,0},++cnt[std::lower_bound(t+1,t+pos+1,a[i].y)-t];
			xm=std::min(xm,a[i].x);
		}
		std::sort(a+1,a+n+1);
		for(int i=n,ym=inf;i>=1;--i){
			if(ym<inf)q[++p]={a[i].x,ym,1};
			ym=std::min(ym,a[i].y);
		}
		build(pos),std::sort(q+1,q+p+1);
		for(int i=1;i<=p;++i){
			if(q[i].op==0)upd(std::lower_bound(t+1,t+pos+1,q[i].y)-t,i);
			else ans=std::min(ans,ask(std::lower_bound(t+1,t+pos+1,q[i].y)-t,pos,q[i].x-all.a,all.d-q[i].y));
		}
		if(st&1)for(int i=1;i<=n;++i)a[i].x=MX-a[i].x;
		if(st&2)for(int i=1;i<=n;++i)a[i].y=MX-a[i].y;
	}
	return ans;
}
struct atom{
	seg cur;ll val;
	inline bool operator < (const atom &o)const{return cur.a>o.cur.a;}
}A[N],B[N],C[N];
namespace DS{
ll mn1[NC],mn2[NC];int M;
void build(int n){
	for(M=1;M<=n+2;M<<=1);
	memset(mn1,63,(M*2+3)<<3),memset(mn2,63,(M*2+3)<<3);
}
void upd(int x,ll C1,ll C2){for(x+=M;x;x>>=1)chmin(mn1[x],C1),chmin(mn2[x],C2);}
ll ask1(int s,int t){
	ll ans=4e18;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=std::min(ans,mn1[s^1]);
		if(t&1)ans=std::min(ans,mn1[t^1]);
	}
	return ans;
}
ll ask2(int s,int t){
	ll ans=4e18;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=std::min(ans,mn2[s^1]);
		if(t&1)ans=std::min(ans,mn2[t^1]);
	}
	return ans;
}
}
ll solve3(){
	all={inf,-inf,inf,-inf};for(int i=1;i<=n;++i)all=merge(all,{a[i].x,a[i].x,a[i].y,a[i].y});
	std::sort(a+1,a+n+1);int pp=-1;for(int i=1;i<=n;++i)if(a[i].y==all.d)pp=i;
	pos=0;for(int i=1;i<=n;++i)t[++pos]=a[i].y;
	std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	seg cur={inf,-inf};int pa=0,pb=0;
	for(int i=1;i<=pp;++i){
		if(i>1)A[++pa]={cur,1LL*(a[pp].x-a[i].x)*(all.d-all.c)};
		cur=merge(cur,{a[i].y,a[i].y});
	}
	cur={inf,-inf};
	for(int i=n;i>=pp;--i){
		if(i<n)B[++pb]={cur,1LL*(a[i].x-a[pp].x)*(all.d-all.c)};
		cur=merge(cur,{a[i].y,a[i].y});
	}
	ll ans=4e18;int len=all.b-all.a;
	std::sort(A+1,A+pa+1),std::sort(B+1,B+pb+1);
	for(int T=0;T<2;++T){
		memcpy(C,A,(pa+3)*sizeof(atom)),memcpy(A,B,(pb+3)*sizeof(atom)),memcpy(B,C,(pa+3)*sizeof(atom)),std::swap(pa,pb);
		int i=1,j=1;DS::build(pos);
		while(i<=pa||j<=pb){
			if(j>pb||(i<=pa&&A[i].cur.a>=B[j].cur.a)){
				DS::upd(std::lower_bound(t+1,t+pos+1,A[i].cur.b)-t,A[i].val,A[i].val+1LL*A[i].cur.b*len);
				++i;
			}
			else{
				int pp=std::lower_bound(t+1,t+pos+1,B[j].cur.b)-t;
				ans=std::min({ans,B[j].val+DS::ask1(1,pp)+1LL*len*(B[j].cur.b-B[j].cur.a),B[j].val+DS::ask2(pp,pos)-1LL*B[j].cur.a*len});
				++j;
			}
		}
	}
	return ans;
}
void MAIN(){
	read(n);if(n==1)return puts("0"),void();
	for(int i=1;i<=n;++i)read(a[i].x,a[i].y);
	ll A=solve1(),B=solve2(),C=solve3();
	printf("%lld\n",std::min({A,B,C}));
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}