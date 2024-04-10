#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

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

int n,m;
#define Maxn 400010
int a[Maxn];
char *ch[Maxn];int *id[Maxn];

int head[Maxn],v[10000010],nxt[10000010],tot=0;
int vis[Maxn],to[Maxn];
int L[Maxn],R[Maxn];
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
}

int lst[Maxn];

int nx[3]={0,0,1};
int ny[3]={-1,1,0};

int node[Maxn],len;

void expand(int *vis,int u,int tag){
	if(vis[u])return;
	vis[u]=tag;
	for(int i=head[u];i;i=nxt[i])expand(vis,v[i],tag);
}

pii seg[Maxn],seq[Maxn];int cnt=0,hh=0;

int main(){
	rd(n);rd(m);
	per(i,n,1){
		ch[i]=new char[m+3];
		id[i]=new int[m+3];
		scanf("%s",ch[i]+1);
	}
	rep(i,1,n)
		rep(j,1,m)
			if(ch[i][j]=='#')id[i][j]=++cnt;
			else id[i][j]=0;
	rep(i,1,n){
		rep(j,1,m)
			if(ch[i][j]=='#'){
				int t=id[i][j];
				if(lst[j])add_edge(t,id[lst[j]][j]);
				per(k,i,lst[j]+1){
					if(j>1&&id[k][j-1])add_edge(t,id[k][j-1]);
					if(j<m&&id[k][j+1])add_edge(t,id[k][j+1]);
				}
				if(i<n&&id[i+1][j])add_edge(t,id[i+1][j]);
				lst[j]=i;
			}
	}
	rep(i,1,m){
		rd(a[i]);
		if(a[i]){
			int at=0;
			rep(j,1,n)
				if(ch[j][i]=='#'){
					at++;
					if(at==a[i])to[i]=id[j][i];
				}
		}
		if(lst[i])node[++len]=id[lst[i]][i];
	}
	rep(i,1,len){
		expand(L,node[i],i);
	}
	per(i,len,1)expand(R,node[i],i);
	cnt=0;
	rep(i,1,m)
		if(to[i]){
			seg[++cnt]=pii(L[to[i]],R[to[i]]);
		}
	sort(seg+1,seg+cnt+1);
	int mn=m+1;
	per(i,cnt,1){
		if(i==cnt||seg[i].SE<mn)seq[++hh]=seg[i];
		mn=min(mn,seg[i].SE);
	}
	reverse(seq+1,seq+hh+1);
	int at=1,res=1;
	rep(i,1,hh)
		if(seq[at].SE<seq[i].FR){
			at=i;
			res++;
		}
	if(!hh)res=0;
	printf("%d\n",res);
	return 0;
}