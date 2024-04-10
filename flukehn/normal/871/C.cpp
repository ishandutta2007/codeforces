#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
inline int pw(int n,int m){int r=1;for(;m;m>>=1,n=1LL*n*n%MOD)if(m&1)r=1LL*r*n%MOD;return r;}
const int N=2e5+11;
int n,M;
map<int,int> ex,ey;
int hd[N],v[N],nxt[N],tot,du[N];
void ins(int a,int b){
	if(!ex[a])ex[a]=++M;
	if(!ey[b])ey[b]=++M;
	a=ex[a],b=ey[b];
	v[++tot]=b,nxt[tot]=hd[a],hd[a]=tot;
	v[++tot]=a,nxt[tot]=hd[b],hd[b]=tot;
	du[a]++,du[b]++;
}
bool vis[N];
int Dx,Dy;
void dfs(int x){
	vis[x]=1,Dy+=du[x],Dx++;
	for(int i=hd[x];i;i=nxt[i])
		if(!vis[v[i]])dfs(v[i]);
}
int main(){
	n=rd();
	rep(i,1,n){
		int x=rd(),y=rd();
		ins(x,y);
	}
	int ans=1;
	rep(i,1,M)if(!vis[i]){
		Dx=0,Dy=0,dfs(i);
//		cout<<Dx<<" "<<Dy<<endl;
		if(Dx*2-2==Dy)ans=1LL*ans*(pw(2,Dx)+MOD-1)%MOD;
		else ans=1LL*ans*pw(2,Dx)%MOD;
	}
	printf("%d\n",ans);
}