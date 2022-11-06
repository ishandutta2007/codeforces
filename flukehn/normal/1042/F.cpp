#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
vector<int> g[N];
int n,K,D[N];
int an;
int dfs(int x,int fa=-1){
	if(D[x]==1)return 1;
	int i,y;
	vector<int> res;
	for(i=0;i<D[x];++i)
	if((y=g[x][i])^fa){
		y=dfs(y,x);
		if(y)res.push_back(y);
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	if(!(y=res.size()))return 0;
	for(i=0;i<y-1;++i){
		if(res[i]+res[i+1]<=K)break;
		++an;
	}
	if(res[i]==K-1)return ++an,0;
	else return res[i]+1;
}
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>K;
	int i,x,y;
	for(i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		++D[x];
		++D[y];
	}
	for(i=1;i<=n;++i)
		if(D[i]>1)break;
	x=dfs(i);
	an+=x>0;
	cout<<an;
}