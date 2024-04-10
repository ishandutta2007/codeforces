#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

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
#define Maxn 100010

typedef pair<unsigned short int,unsigned short int> puu;

const int V=25600005;
const int Mod=1e7+7;
int head[Mod],val[V],nxt[V];
puu seq[V];int tot=0;
void Add(puu cur,int id){
	int key=(1ll*cur.FR*n+cur.SE)%Mod;
	for(int i=head[key];i;i=nxt[i])
		if(cur==seq[i]){
			val[i]=min(val[i],id);
			return;
		}
	tot++;seq[tot]=cur;val[tot]=id;nxt[tot]=head[key];head[key]=tot;
}
int query(puu cur){
	int key=(1ll*cur.FR*n+cur.SE)%Mod;
	for(int i=head[key];i;i=nxt[i])
		if(cur==seq[i])return val[i];
	return m+1;
}

pii seg[Maxn];
int ans[Maxn];int I;

int lowbit(int x){return x&(-x);}
void add(int a,int b,int id){
	for(int i=a;i<=n;i+=lowbit(i))for(int j=b;j<=n;j+=lowbit(j))
	Add(puu(i,j),id);
}

int query(int a,int b){
	int res=m+1;
	for(int i=a;i;i-=lowbit(i))for(int j=b;j;j-=lowbit(j))res=min(res,query(puu(i,j)));
	return res;
}

void dfs(int l,int r){
	int id=query(n+1-l,r);
	if(id==m+1)return;
	ans[I]+=seg[id].SE-seg[id].FR+1;
	if(l<seg[id].FR)dfs(l,seg[id].FR-1);
	if(seg[id].SE<r)dfs(seg[id].SE+1,r);
}

vector<int> vec[Maxn];

int main(){
	rd(n);rd(m);
	rep(i,1,m){
		rd(seg[i].FR);rd(seg[i].SE);
		vec[seg[i].SE-seg[i].FR+1].push_back(i);
	}
	per(i,n,1){
		I=i;
		for(int j=0;j<vec[i].size();++j)add(n+1-seg[vec[i][j]].FR,seg[vec[i][j]].SE,vec[i][j]);
		dfs(1,n);
	}
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}