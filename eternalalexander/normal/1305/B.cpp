#include <bits/stdc++.h>
#define maxn 1005
char s[maxn];
int n,vis[maxn],pr[maxn],cnt;
int main(){
	scanf("%s",s+1);n=std::strlen(s+1);
	for(int i=n;i>=1;i--){
		if(s[i]=='(')continue;
		for(int j=1;j<=i;++j){
			if(s[j]=='('&&!vis[j]){
				pr[j]=i;
				vis[j]=1;
				cnt++;
				break;
			}
		}
	}printf("%d\n",cnt?1:0);
	if(cnt)printf("%d\n",cnt*2);
	for(int i=1;i<=n;++i)
		if(vis[i])
			printf("%d ",i);
	for(int i=n;i>=1;--i)
		if(vis[i])
			printf("%d ",pr[i]);
	return 0;
}