#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=4e5+2,INF=1e9;
int n,m,k,ans,sp[N];
int d1[N],d2[N],a[N],b[N],c[N],d[N];
vector<int>e[N];
V input(){
	n=getint(),m=getint(),k=getint();
	FOR(i,1,k)sp[i]=getint();
	int x,y;
	FOR(i,1,m){
		x=getint(),y=getint();
		e[x].push_back(y);
		e[y].push_back(x);
	}
}
queue<int>q;
I cmp(int x,int y){return d1[x]<d1[y];}
V init(){
	FOR(i,1,n)d1[i]=d2[i]=INF;
	q.push(1),d1[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:e[u])if(d1[v]==INF)
			d1[v]=d1[u]+1,q.push(v);
	}
	q.push(n),d2[n]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:e[u])if(d2[v]==INF)
			d2[v]=d2[u]+1,q.push(v);
	}
	sort(sp+1,sp+1+k,cmp);
	ROF(i,k,1)b[i]=max(b[i+1],d2[sp[i]]);
}
V work(){
	ans=0;
	int x,y;
	FOR(i,1,k-1)ans=max(ans,d1[sp[i]]+b[i+1]+1);
	ans=min(ans,d1[n]),cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}