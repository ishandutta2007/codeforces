#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,len,a[N],b[N],c[N],cnt,need,vis[N],qwq;
vector<pair<int,int> > G[N];
vector<int> ans[N];
void dfs(int u){
	vis[u]=1;
	while(!G[u].empty()){
		int v=G[u].back().first,w=G[u].back().second;
		G[u].pop_back();
		dfs(v);
		ans[cnt].push_back(w);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=c[i]=read();
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;++i){
		if(c[i]^c[i-1])++len;
		b[i]=len;
	}
	len=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(c+1,c+len+1,a[i])-c;
	}
	for(int i=1;i<=n;++i){
		if(a[i]^b[i])G[a[i]].push_back(make_pair(b[i],i)),++need;
	}
	if(need>m){
		return !printf("-1\n");
	}
	if(!need){
		return !printf("0\n");
	}
	for(int i=1;i<=len;++i){
		if(!vis[i]&&!G[i].empty()){
			++cnt,dfs(i);
		}
	}
	if(cnt<=1||m-need<=1){
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			printf("%d\n",(int)ans[i].size());
			for(auto x:ans[i]){
				printf("%d ",x);
			}
			printf("\n");
		}
		return 0;
	}
	printf("%d\n",qwq=cnt+2-min(m-need,cnt));
	printf("%d\n",min(m-need,cnt));
	int tot=0;
	for(int i=1;i<=min(m-need,cnt);++i){
		printf("%d ",ans[i].back()),tot+=ans[i].size();
	}
	printf("\n");
	reverse(ans+1,ans+min(m-need,cnt)+1);
	printf("%d\n",tot);
	for(int i=1;i<=min(m-need,cnt);++i){
		for(auto x:ans[i]){
			printf("%d ",x);
		}
	}
	printf("\n");
	for(int i=min(m-need,cnt)+1;i<=cnt;++i){
		printf("%d\n",(int)ans[i].size());
		for(auto x:ans[i]){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}