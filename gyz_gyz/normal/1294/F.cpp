#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct dp{
	int w=0;vector<int>p;
	void upd(const dp&a){if(a.w>w)*this=a;}
	friend dp operator +(dp a,const dp&b){
		for(auto&i:b.p)a.p.push_back(i);
		a.w+=b.w;return a;
	}
}a[4][N],ans;
int n,f[N];vector<int>p[N];
void dfs(int x){
	a[1][x].p.push_back(x);a[2][x].w=a[3][x].w=-n;
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);
		dep(j,3,1)rep(k,1,j)a[j][x].upd(a[j-k][x]+a[k][i]);
	}
	ans.upd(a[3][x]);a[3][x]=dp();
	rep(i,1,2)++a[i][x].w;
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);printf("%d\n",ans.w);
	for(auto&i:ans.p)printf("%d ",i);
}