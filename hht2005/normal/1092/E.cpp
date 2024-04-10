#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int>S[N];
int d[N],Mid[N],f[N],fa[N],T,L,cnt;
void dfs(int x,int dep) {
	f[x]=1;
	if(L<=dep) {
		L=dep;
		T=x;
	}
	for(int y:S[x]) {
		if(y==fa[x])continue;
		fa[y]=x;
		dfs(y,dep+1);
	}
}
signed main() {
	int n,m,a,b,Min=1e9,id=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(b);
		S[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		if(!f[i]) {
			T=L=0;
			dfs(i,0);
			L=0;
			fa[T]=0;
			dfs(T,0);
			d[++cnt]=L;
			Mid[cnt]=T;
			for(int i=L/2;i;i--)Mid[cnt]=fa[Mid[cnt]];
		}
	for(int i=1;i<=cnt;i++) {
		int Max=0,M[2]={0,0};
		for(int j=1;j<=cnt;j++) {
			Max=max(Max,d[j]);
			if(j!=i) {
				Max=max(Max,(d[i]+1)/2+(d[j]+1)/2+1);
				int tmp=(d[j]+1)/2;
				if(M[0]<tmp)swap(M[0],tmp);
				if(M[1]<tmp)swap(M[1],tmp);
			}
		}
		if(cnt>2)Max=max(Max,M[0]+M[1]+2);
		if(Min>Max) {
			Min=Max;
			id=i;
		}
	}
	printf("%d\n",Min);
	for(int i=1;i<=cnt;i++)
		if(id!=i)printf("%d %d\n",Mid[i],Mid[id]);
	return 0;
}