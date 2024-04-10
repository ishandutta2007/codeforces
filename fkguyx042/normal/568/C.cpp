#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define CH (ch=getchar())
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,V)     for(__typeof(*V.begin()) i:  V)
#define For(i,a,b)   for(int i=(int)a;i<=(int)b;i++)
#define Forn(i,a,b)  for(int i=(int)a;i>=(int)b;i--)
#define pend(x)      ((x)=='\n'||(x)=='\r'||(x)=='\t'||(x)==' ')
using namespace std;
typedef long long ll;
typedef double db;
const int N=555;
const int M=4*N*(N-1);

inline int IN(){
	char ch;CH; int f=0,x=0;
	for(;pend(ch);CH); if(ch=='-')f=1,CH;
	for(;!pend(ch);CH) x=x*10+ch-'0';
	return (f)?(-x):(x);
}

char s[N];
int st[N],dfn[N],low[N],In[N],stk[N],top,dex,scc,B[N];
int l,n,m,a[N],id[N][2],cnt,Tim,h[15],ans[N];
vector<int> E[N],_E[N],_[N],Z;

void addedge(int u,int v){
	E[u].pb(v);
}

void ban(int x,int y){
	addedge(id[x][y],id[x][y^1]);
}

void tarjan(int x){
	low[x]=dfn[x]=++dex;
	In[stk[++top]=x]=1;
	rep(v,E[x]){
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else
		if(In[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		int p; ++scc;
		do{
			p=stk[top];
			B[p]=scc;
			--top;
			In[p]=0;
		}while(p^x);
	}
}

bool judge(){
	For(i,1,cnt) dfn[i]=low[i]=In[i]=stk[i]=B[i]=0;
	dex=top=scc=0;
	For(i,1,cnt) if(!dfn[i]) tarjan(i);
	For(i,1,n) if(B[id[i][0]]==B[id[i][1]]) return false;
	return true;
}

void gou(int x){
	For(i,1,x) ans[i]=st[i];
	For(i,x+1,n){
		++Tim;
		For(j,1,l){
			if(h[a[j]]==Tim)continue;
			h[a[j]]=Tim;
			For(k,1,cnt) _[k]=E[k];
			ban(i,a[j]^1);
			if(judge()){
				ans[i]=j;
				break;
			}
			For(k,1,cnt) E[k]=_[k];
		}
	}
}

void print(){
	if(!ans[1]){
		puts("-1");
		return;
	}
	For(i,1,n) printf("%c",ans[i]+'a'-1);
	puts("");
}

int main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	For(i,1,l) a[i]=(s[i]=='V');
	n=IN(),m=IN();
	For(i,1,n) For(j,0,1) id[i][j]=++cnt;
	For(i,1,m){
		char ch;
		int u=IN(),tu;CH;tu=(ch=='V');
		int v=IN(),tv;CH;tv=(ch=='V');
		addedge(id[u][tu],id[v][tv]);
		addedge(id[v][tv^1],id[u][tu^1]);
	}
	
	bool flag;
	flag=0;For(i,1,l) if(a[i]) flag=1; 
	if(!flag) For(i,1,n) ban(i,1);
	
	flag=0;For(i,1,l) if(!a[i]) flag=1; 
	if(!flag) For(i,1,n) ban(i,0);
	
	
	scanf("%s",s+1);
	For(i,1,n) st[i]=s[i]-'a'+1;
	Forn(i,n,1){
		int A=s[i]-'a'+1+(i<n);
		++Tim;
		For(j,1,cnt) _E[j]=E[j];
		For(j,A,l){
			if(h[a[j]]==Tim)continue;
			h[a[j]]=Tim;
			st[i]=j;
			For(k,1,cnt) E[k]=_E[k];
			For(k,1,i) ban(k,a[st[k]]^1);
			if(judge()){
				gou(i);
				print();
				exit(0);
			}
		}
		For(j,1,cnt) E[j]=_E[j];
	}
	puts("-1");
	return 0;
}