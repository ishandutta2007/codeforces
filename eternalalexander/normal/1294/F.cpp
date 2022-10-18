#include <bits/stdc++.h>
#define maxn 200005
int n,u,v,ans,a,b,c,son[maxn],fp[maxn],g[maxn],h[maxn];
int cmp(int a,int b){
	return h[a]>h[b];
}
std::vector<int>ch[maxn];
void dfs(int u,int f){
	for(int i=0;i<ch[u].size();++i){
		if (ch[u][i]==f)continue;
		dfs(ch[u][i],u);
	}std::sort(ch[u].begin(),ch[u].end(),cmp);
	h[u]=h[ch[u][0]]+1;
	if (h[u]!=1)son[u]=son[ch[u][0]];
	else son[u]=u;
}
 
void dfs1(int u,int f){
	int len=ch[u].size();
	if (len==1)return;
	for(int i=0;i<len-1;i++){
		if (i!=0){
			g[ch[u][i]]=std::max(g[u],h[ch[u][0]])+1;
			if (g[u]>h[ch[u][0]])fp[ch[u][i]]=fp[u];
			else fp[ch[u][i]]=son[ch[u][0]];
		}else {
			g[ch[u][i]]=std::max(g[u],len==2?-1:h[ch[u][1]])+1;
			if (len==2||g[u]>=h[ch[u][1]])fp[ch[u][i]]=fp[u];
			else fp[ch[u][i]]=son[ch[u][1]];
		}dfs1(ch[u][i],u);
	}
	int ans1=0,ans2=0;
	for(int i=0;i<len-1;++i){
		if (i<2)ans1+=h[ch[u][i]],ans2+=h[ch[u][i]];
		else if (i<3)ans1+=h[ch[u][i]];
	}ans2+=g[u];
	//printf("%d: %d %d %d %d\n",u,len,h[u],g[u],fp[u]);
	//printf("%d %d\n",ans1,ans2);
	if (len>2&&!(u==1&&len==3)&&ans1>ans){
		ans=ans1;
		//printf("*%d\n",u);
		a=son[ch[u][0]];b=son[ch[u][1]];c=son[ch[u][2]];
	}if (len>1&&ans2>ans){
		ans=ans2;
	//	printf("+");
		a=son[ch[u][0]];b=len>2?son[ch[u][1]]:u;c=fp[u];
	}
}
 
int main(){
	scanf("%d",&n);
	ch[1].push_back(0);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}dfs(1,0);fp[1]=1;
	dfs1(1,0);
	printf("%d\n%d %d %d",ans,a,b,c);
	return 0;
}