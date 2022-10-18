#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
ll sum[maxn][2],size[maxn][2],ans1,ans2;
int depth[maxn],u,v,n;
std::vector<int>ch[maxn];
void dfs(int u,int f){
	depth[u]=depth[f]+1;
	size[u][depth[u]%2]=1;
	sum[u][depth[u]%2]=depth[u];
	for(int i=0;i<ch[u].size();++i){
		int v=ch[u][i];
		if (v==f)continue;
		dfs(v,u);
		ll s1=size[u][0]+size[u][1],s2=size[v][0]+size[v][1];
		ans1+=s1*(sum[v][0]+sum[v][1]-depth[u]*s2);
		ans1+=s2*(sum[u][0]+sum[u][1]-depth[u]*s1);
		ans1-=size[u][0]*size[v][1]+size[u][1]*size[v][0];
		//printf(">%d %d*%d\n",ans1,(size[v][0]+size[v][1]),(sum[u][0]+sum[u][1]-depth[u]));
		ans2+=size[u][0]*size[v][1]+size[u][1]*size[v][0];
		size[u][0]+=size[v][0];
		size[u][1]+=size[v][1];
		sum[u][0]+=sum[v][0];
		sum[u][1]+=sum[v][1];
	}//printf("%d : %d %d, %d %d\n",u,sum[u][0],sum[u][1],size[u][0],size[u][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}dfs(1,0);
//	printf("%lld %lld\n",ans1,ans2);
	std::cout<<ans1/2+ans2;
	return 0;
}