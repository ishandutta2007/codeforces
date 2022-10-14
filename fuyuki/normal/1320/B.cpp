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
const int N=2e5+1,INF=0x3f3f3f3f;
int n,m,k,a[N],tag[N];
vector<int>e[N];
V input(){
	n=getint(),m=getint();int x,y;
	FOR(i,1,m){
		x=getint(),y=getint();
//		e[x].push_back(y);
		e[y].push_back(x);
	}
	FOR(i,1,n)tag[i]=-N;
	k=getint();
	FOR(i,1,k)a[i]=getint(),tag[a[i]]=i;
}
int d0[N],d1[N],dis[N],minn,maxn;
queue<int>q;
V init(){
}
V work(){
	q.push(a[k]),dis[a[k]]=1;
	while(!q.empty()){
		int u=q.front(),val;
		q.pop();
		for(int v:e[u])
			if(!dis[v]){
				dis[v]=dis[u]+1,q.push(v);
				if(tag[u]==tag[v]+1)
					minn++,maxn++,d0[v]=d1[v]=1;
			}
			else if(dis[v]==dis[u]+1){
				if(tag[u]!=tag[v]+1&&d0[v])
					minn--,d0[v]=0;
				if(tag[u]==tag[v]+1&&!d1[v])
					maxn++,d1[v]=1;
			}
	}
	cout<<k-1-maxn<<' '<<k-1-minn<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}