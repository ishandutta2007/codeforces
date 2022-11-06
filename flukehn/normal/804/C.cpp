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
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)/*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=3e5+5;
vector<int> v[N];
vector<int> a[N];
int n,m,ans[N];
set<int> S;
void dfs(int x,int f=0){
	S.clear();
	rep(i,0,v[x].size()-1)
		if(ans[v[x][i]])S.insert(ans[v[x][i]]);
	int now=1;
	rep(i,0,v[x].size()-1)if(!ans[v[x][i]]){
		while(S.count(now))now++;
		ans[v[x][i]]=now++; 
	}
	rep(i,0,a[x].size()-1)
		if(a[x][i]!=f)dfs(a[x][i],x);
}
int main(){
	n=rd(),m=rd();
	int A=1;
	rep(i,1,n){
		int t=rd(),x;
		A=max(A,t);
		rep(j,1,t) {
			x=rd();
			v[i].pb(x);
		}
	}
	rep(i,2,n){
		int u=rd(),v=rd();
		a[u].pb(v),a[v].pb(u);
	}
	printf("%d\n",A);
	dfs(1);
	rep(i,1,m)printf("%d%c",ans[i]?ans[i]:1," \n"[i==m]);
}