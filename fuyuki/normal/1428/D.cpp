#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
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
const int N=5e5+1,mod=1e9+7;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
P b[N];
int T,n,top;
int a[N],id[N],tag[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	int p1=n,p2=n,p3=n,now=n+1;
	ROF(i,n,1){
		if(a[i]==1){
			b[++top]=P(--now,i);
			id[i]=now;
		}
		if(a[i]==2){
			while(p1>=i)
				if(a[p1]==1&&!tag[p1])break;
				else p1--;
			if(p1<i)return void(cout<<"-1");
			b[++top]=P(id[p1],i),tag[p1]=1;
		}
		if(a[i]==3){
			while(p3>i)
				if(a[p3]>1&&!tag[p3])break;
				else p3--;
			if(p3>i){
				b[++top]=P(--now,i);
				b[++top]=P(now,p3),tag[p3]=1;
				id[i]=now;
				continue;
			}
			while(p2>i)
				if(a[p2]==1&&!tag[p2])break;
				else p2--;
			if(p2==i)return void(cout<<"-1");
			b[++top]=P(--now,i);
			b[++top]=P(now,p2),tag[p2]=1;
			id[i]=now;
		}
	}
	cout<<top<<'\n';
	FOR(i,1,top)
		cout<<b[i].first<<' '<<b[i].second<<'\n';
}
V init(){
}
V work(int u=0,int v=0){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}