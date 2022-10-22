#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

const int oo=2e9;
const ll inf=1e18;
int n,m;
#define Maxn 605

void calc(int *a){
	int lst=oo;
	rep(i,0,n-1){
		a[i]=lst=min(lst+1,a[i]);
	}
	rep(i,0,n-1){
		a[i]=lst=min(lst+1,a[i]);
	}
}

int way[Maxn][Maxn];
ll dist[Maxn];
void cmin(ll &x,ll y){x=min(x,y);}
bool vis[Maxn];
int add(int a,int b){return a+b>=n?a+b-n:a+b;}
void Bfs(int S){
	rep(u,0,n-1)dist[u]=inf,vis[u]=0;
	dist[S]=0;
	rep(K,1,n){
		int u=-1;
		rep(i,0,n-1)
			if(!vis[i]){
				if(u==-1)u=i;
				else if(dist[i]<dist[u])u=i;
			}
		ll d=dist[u];int t=d%n;
		rep(i,0,n-1){
			cmin(dist[add(t,i)],d+way[u][i]);
		}
		vis[u]=true;
	}
}

int main(){
	rd(n);rd(m);int a,b,c;
	rep(u,0,n-1)rep(i,0,n-1)way[u][i]=oo;
	rep(i,1,m){
		rd(a);rd(b);rd(c);
		way[a][b]=c;
	}
	rep(i,0,n-1)calc(way[i]);
	rep(i,0,n-1){
		Bfs(i);
		rep(j,0,n-1)printf("%lld ",dist[j]);
		puts("");
	}
	return 0;
}