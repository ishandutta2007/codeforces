#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1505

typedef long long ll;

vector<int> E[M];

ll pos_x,pos_y;
struct node{
	int x,y,id;
	bool operator <(const node &s) const{
		return y<s.y;
	}
}A[M];

bool cmp(node a,node b) {
	return (a.x-pos_x)*(b.y-pos_y)>(a.y-pos_y)*(b.x-pos_x);
}

int Ans[M];

int Fa[M],sz[M];
void dfs(int x,int fr) {
	Fa[x]=fr;sz[x]=1;
	FOR(i,0,E[x].size()-1) {
		int y=E[x][i];
		if(y==fr) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}
void solve(int L,int R,int x) {
	int s=L;
	FOR(i,L+1,R) if(A[s].x>A[i].x) s=i;
	node tmp=A[L];
	A[L]=A[s];
	A[s]=tmp;
	Ans[A[L].id]=x;
	pos_x=A[L].x;
	pos_y=A[L].y;
	L++;
	if(L>R) return ;
	sort(A+L,A+R+1,cmp);
	FOR(i,0,E[x].size()-1) {
		int y=E[x][i];
		if(y==Fa[x]) continue;
		solve(L,L+sz[y]-1,y);
		L+=sz[y];
	}
}
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,2,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	FOR(i,1,n) {
		scanf("%d%d",&A[i].x,&A[i].y);
		A[i].id=i;
	}
	dfs(1,0);
	solve(1,n,1);
	FOR(i,1,n) printf("%d ",Ans[i]);
	putchar('\n');
	return 0;
}