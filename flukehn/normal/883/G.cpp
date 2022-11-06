#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=3e5+11;
struct Eg{int u,v,t,f;}E[N];
struct Edge{
	int t;int v;
	Edge *nxt,*r;
}pl[N<<2],*cur=pl,*G[N];
int n,m,S,tot;
char ans[N];
bool vis[N];
void build(){
	tot=0;
	memset(ans,0,sizeof ans);
	memset(vis,0,sizeof vis);
	vis[S]=1;
	cur=pl;
	memset(G,0,sizeof G);
	for(Eg *i=E+1;i!=E+m+1;i++){
		int u = i->u, v = i->v;
		if(i->t==1) {
			cur->v=i->v,cur->t=-1;
			cur->nxt=G[u],G[u]=cur++;
		} else {
			cur->v=i->v,cur->t=i-E;
			cur->nxt=G[u],cur->r=cur+1,G[u]=cur++;
			
			cur->v=i->u,cur->t=i-E;
			cur->nxt=G[v],cur->r=cur-1,G[v]=cur++;
		}
	}
}
int q[N];
void bfs1(){
	int h=0,t=0;
	q[t++]=S;
	while(h<t){
		int x=q[h++];tot++;
		Es(x,i)if(!vis[i->v]){
			if(i->t){
				if(~i->t){
					i->r->t=0;
					ans[E[i->t].f]="-+"[x==E[i->t].u];
					i->t=-1;
					q[t++] = i->v;
					vis[i->v] = 1;
				} else {
					q[t++] = i->v;
					vis[i->v] = 1;
				}
			}
		}
	}
}
void bfs2(){
	int h=0,t=0;
	q[t++]=S;
	while(h<t){
		int x=q[h++];tot++;
		Es(x,i)if(!vis[i->v]){
			if(i->t){
				if(~i->t){
					i->r->t=-1;
					ans[E[i->t].f]="+-"[x==E[i->t].u];
					i->t=0;
				} else {
					q[t++] = i->v;
					vis[i->v] = 1;
				}
			}
		}
	}
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd(),S=rd();
	int ctt=0;
	rep(i,1,m){
		E[i].t=rd(),E[i].u=rd(),E[i].v=rd();
		if(E[i].t^1) E[i].f=++ctt;
	}
	build(),bfs1();
	printf("%d\n",tot);
	rep(i,1,ctt)if(ans[i])putchar(ans[i]);
	else putchar('-');
	putchar('\n');
	
	build(),bfs2();
	printf("%d\n",tot);
	rep(i,1,ctt)if(ans[i])putchar(ans[i]);
	else putchar('-');
}