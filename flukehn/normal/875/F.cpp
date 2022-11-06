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
const int N=200011;
int n,m;
struct Node{
	int a,b,w;
	bool operator<(const Node&t)const{
		return w>t.w;
	}
} e[N];
struct UNI{
	int f[N],used[N],siz[N];
	void init(){rep(i,1,n)f[i]=i,siz[i]=1,used[i]=0;}
	int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
	inline ck(int i){return used[i]!=siz[i];}
	void uni(int i,int j){
		f[i]=j,siz[j]+=siz[i];
		used[j]+=used[i]+1;
	}
} ui;
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd();
	ui.init();
	rep(i,1,m){
		e[i].a=rd();
		e[i].b=rd();
		e[i].w=rd();
	}
	sort(e+1,e+m+1);
	int ans=0;
	rep(i,1,m){
		int x=ui.fa(e[i].a),y=ui.fa(e[i].b);
		if(x!=y){
			if(ui.ck(x)||ui.ck(y)){
				ui.uni(x,y);
				ans+=e[i].w;
			}
		}else if(ui.ck(x))ans+=e[i].w,ui.used[x]++;
	}
	cout<<ans<<endl;
}