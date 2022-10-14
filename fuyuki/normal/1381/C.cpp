#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
const int N=2e5+100,INF=0x3f3f3f3f;
vector<int>pos[N];
int T,n,m,X,Y,S,now,tot,sta[N];
int a[N],c[N],out[N];
priority_queue<P>q;
V input(){
	n=getint(),X=getint(),Y=getint();
	FOR(i,1,n+1)c[i]=0;
	FOR(i,1,n)a[i]=getint(),c[a[i]]++,pos[a[i]].push_back(i);
}
V init(){
	FOR(i,1,n+1){
		if(!c[i])S=i;
		q.push(P(c[i],i));
	}
	Y-=X,tot=0;
	while(X--){
		P x=q.top();q.pop();int p=x.second;
		out[pos[p].back()]=p;
		pos[p].pop_back();
		q.push(P(--c[p],p));
	}
	int maxn=q.top().first;
	FOR(i,1,n+1){
		while(!pos[i].empty())
			sta[++tot]=pos[i].back(),pos[i].pop_back();
	}
	if(Y)FOR(i,1,tot){
		int p=(i+maxn-1)%tot+1;
		if(a[sta[i]]^a[sta[p]]){
			out[sta[i]]=a[sta[p]];
			if(!--Y)break;
		}
	}
	if(Y)return void(cout<<"NO\n");
	cout<<"YES\n";
	FOR(i,1,n)cout<<(!out[i]?S:out[i])<<" \n"[i==n];
}
V work(){
	FOR(i,1,n)out[i]=0;
	while(!q.empty())q.pop();
	while(tot)sta[tot--]=0;
	
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}