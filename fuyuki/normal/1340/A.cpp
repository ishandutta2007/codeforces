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
const int N=2e5+2;
int T,n;
int a[N],fa[N],siz[N];
multiset<int>mp;
V input(){
	n=getint(),mp.clear();
	FOR(i,1,n)a[i]=getint();
}
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
V init(){
	FOR(i,1,n)fa[i]=i,siz[i]=1,mp.insert(1);
	fa[n+1]=0;
}
I top(){return *--mp.end();}
V del(int x){mp.erase(mp.find(x));}
V work(){
	FOR(i,1,n)
		if(siz[a[i]]==top()){
			int x=a[i],y=find(a[i]+1);
			del(siz[x]);
			if(y)
				del(siz[y]),siz[y]+=siz[x],mp.insert(siz[y]);
			fa[x]=y;
		}
		else return void(cout<<"No\n");
	cout<<"Yes\n";
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}