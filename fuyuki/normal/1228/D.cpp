#include<set>
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
#define ll long long int
#define B inline bool
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1,mod=1e9+7;
set<int>mp[N];
struct bian{
	int x,y;
	V input(){
		x=getint(),y=getint();
		if(x<y)swap(x,y);
		mp[x].insert(y),mp[y].insert(x);
	}
	B operator<(const bian&u)const{
		return x==u.x?y<u.y:x<u.x;
	}
}a[N<<2];
int n,m;
int id[N];
int tot[4];
int b[4][N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,m)a[i].input();
}
V init(){
	sort(a+1,a+1+m);
}
V work(){
	int cur=1;
	FOR(i,1,n){
		int can[4]={1,1,1,1};
		while(a[cur].x==i)
			can[id[a[cur++].y]]=0;
		FOR(j,1,3)if(can[j])id[i]=j;
		if(!id[i])return void(cout<<"-1");
		b[id[i]][++tot[id[i]]]=i;
	}
	FOR(x,1,3)FOR(y,x+1,3){
		FOR(i,1,tot[x])FOR(j,1,tot[y])
			if(mp[b[x][i]].find(b[y][j])==mp[b[x][i]].end())
				return void(cout<<"-1");
	}
	FOR(i,1,3)if(tot[i]==0)return void(cout<<"-1");
	FOR(i,1,n)cout<<id[i]<<' ';
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}