#include <bits/stdc++.h>
#define maxn 1000005
int n,a[maxn],pl[maxn],p[maxn],vis[maxn];
void check(){
	for(int i=1;i<=n;++i)vis[i]=0;vis[n+1]=1;
	int flag=0;
	for(int i=1;i<=n;++i){
		if(!flag&&!vis[pl[i]+1])flag=1;
		else if(flag&&!vis[pl[i]-1]){puts("No");return ;}
		else if(flag&&vis[pl[i]+1])flag=0;
		vis[pl[i]]=1;
	}puts("Yes");
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			pl[a[i]]=i;
		}
		check();
			
	}
			
	return 0;
}