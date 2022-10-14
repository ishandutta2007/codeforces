#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1,mod=998244353,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int P;
ll x,w[50],pw[50];
struct node{
	char opt;
	ll x,y;
	V output(){
		cout<<x<<' '<<opt<<' '<<y<<'\n';
	}
};
vector<node>out;
V add(ll x,ll y){out.push_back((node){'+',x,y});}
V mul(ll x,ll y){out.push_back((node){'^',x,y});}
V input(){
	ll v;
	cin>>x;
	mul(x,x);
	FOR(i,1,20)if(x>>i&1)P=i;
	FOR(i,0,20)pw[i]=x<<i,add(pw[i],pw[i]);
	v=x;
	FOR(i,P+1,45){
		add(v,v),v<<=1;
		if(v>>P&1)mul(v,x),v^=x;
		w[i]=v;
//		cout<<((v>>p)<<p)<<'\n';
	}
	w[P]=x;
}
V find(int p){
	ll v,y;
	FOR(i,1,x*5){
		v=x*i;
		FOR(j,p+1,45)if(v>>j&1)v^=w[j];
		if((v>>p)==1){
			y=0;
			FOR(j,0,20)if(i>>j&1)
				add(y,pw[j]),y+=pw[j];
			v=x*i;
			FOR(j,p+1,45)if(v>>j&1)
				mul(v,w[j]),v^=w[j];
			w[p]=v;
			if(!p)return;
			FOR(j,p+1,45)if(w[j]>>p&1)
				mul(w[j],v),w[j]^=v;
			return;
		}
	}
	cerr<<"fail\n";
}
V init(){
	ll v,y;
	ROF(k,P-1,0)find(k);
}
V work(){
	cout<<out.size()<<'\n';
	for(node v:out)v.output();
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}