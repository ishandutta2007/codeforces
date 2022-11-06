#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;
const int N=1e5+11;
struct Edge{
	int v,w;Edge *nex;
}pl[N],*cur=pl,*G[N];
void ins(int u,int v,int w){
	cur->v=v,cur->nex=G[u];
	cur->w=w,G[u]=cur++;
}
int n;
const ll INF=100000000000000000LL;
ll a[N];
#define pe puts("NO"),exit(0)
void dfs(int x,int fa=0,int w=0) {
	Es(x,i){
		dfs(i->v,x,i->w);
		if(a[i->v]>=0)a[x]+=a[i->v];
		else{
			ll na=-a[i->v];
			if(na>=INF/i->w)pe;
			a[x]-=na*i->w;
			if(a[x]<-INF)pe;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		ll x;
		cin>>x;
		a[i]-=x;
	}
	rep(i,2,n){
		int x,k;
		cin>>x>>k;
		ins(x,i,k);
	}
	dfs(1);
	puts(a[1]>=0?"YES":"NO");
}
/*
10
2 8 6 1 2 7 6 9 2 8
4 9 4 3 5 2 9 3 7 3
1 8
2 8
3 8
4 10
5 1
6 4
7 3
8 10
9 2

YES
*/