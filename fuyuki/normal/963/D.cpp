#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1,INF=0x3f3f3f3f;
queue<int>q{{1}};
vector<int>pos[N];
char a[N],big[N],*b[N],*np(big);
int n,m,tot=1,len[N],ans[N],c[N];
int ch[N][26],fa[N],pre[N],tag[N];
V cmin(int&x,int y){if(y-x>>31)x=y;}
V input(){
	scanf("%s%d",a+1,&m),n=strlen(a+1);
	FOR(i,1,m)b[i]=np,scanf("%d%s",c+i,b[i]),len[i]=strlen(b[i]),np+=len[i];
}
V ins(char*st,int n,int id){
	int*to,p=1;
	FOR(i,0,n-1)*(to=&ch[p][st[i]-'a'])||(*to=++tot),p=*to;
	tag[p]=id;
}
V init(){
	FOR(i,0,25)ch[0][i]=1;
	FOR(i,1,m)ins(b[i],len[i],i);
	for(int u,v;!q.empty();q.pop()){
		v=fa[u=q.front()],pre[u]=tag[v]?v:pre[v];
		FOR(i,0,25)
			if(!ch[u][i])ch[u][i]=ch[v][i];
			else fa[ch[u][i]]=ch[v][i],q.push(ch[u][i]);
	}
}
V modify(int p,int w){for(;p;p=pre[p])if(tag[p])pos[tag[p]].push_back(w);}
V solve(const vector<int>&t,int k,int w){
	int n=t.size(),out=INF;
	FOR(i,k-1,n-1)cmin(out,t[i]-t[i-k+1]);
	cout<<(out==INF?-1:out+w)<<'\n';
}
V work(){
	int p=1;
	FOR(i,1,n)p=ch[p][a[i]-'a'],modify(p,i);
	FOR(i,1,m)solve(pos[i],c[i],len[i]);
}
int main(){
	input();
	init();
	work();
	return 0;
}