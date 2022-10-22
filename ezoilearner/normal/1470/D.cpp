#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 300010
#define cout cerr
#define FR first
#define SE second
int type[Maxn];
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

void init(){
	memset(type,-1,sizeof(int)*(n+1));
	tot=0;memset(head,0,sizeof(int)*(n+1));
}

int Q[Maxn],hd,tl;
void color(int u){
	type[u]=1;
	for(int i=head[u];i;i=nxt[i])
		if(type[v[i]]==-1){
			type[v[i]]=0;
			Q[tl++]=v[i];
		}
}
void Add(int u){
	for(int i=head[u];i;i=nxt[i])
		if(type[v[i]]==-1){
			color(v[i]);
		}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
} 

int seq[Maxn],cnt;

int main(){
	int T;rd(T);
	while(T--){
		rd(n);rd(m);init();
		int s,e;
		rep(i,1,m){
			rd(s);rd(e);
			add_edge(s,e);
		}
		hd=tl=0;
		color(1);
		while(hd<tl){
			int u=Q[hd];hd++;
			Add(u);
		}
		bool flag=true;
		cnt=0;
		rep(i,1,n)
			if(type[i]==-1){
				puts("NO");
				flag=false;
				break;
			}else if(type[i]==1)seq[++cnt]=i;
		if(flag){
			puts("YES");
			printf("%d\n",cnt);
			rep(i,1,cnt)printf("%d ",seq[i]);puts("");
		}
	}
	return 0;
}