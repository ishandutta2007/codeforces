#include <bits/stdc++.h>

int t;
char S[105],T[105],P[105];
int vis[28]={0},dp[105][105]={0};;

int main() {
	scanf("%d",&t);
	while (t--){
		int flag=0;
		scanf("%s%s%s",S+1,T+1,P+1);
		int n=std::strlen(S+1),m=std::strlen(T+1);
		std::memset(vis,0,sizeof(vis));
		for (int i=1;i<=m;++i) vis[T[i]-'a']++;
		for (int i=1;i<=n;++i){
			if (vis[S[i]-'a']==0) {printf("NO\n");flag=1;break;}
			vis[S[i]-'a']--;
		} if (flag==1) continue;
		for (int i=1;i<=std::strlen(P+1);++i) {
			if (vis[P[i]-'a']) vis[P[i]-'a']--;
		} for (int i=0;i<26;++i) if (vis[i]) {printf("NO\n");flag=1;break;}
		if (flag==1) continue;
		std::memset(dp,0,sizeof(dp));
		dp[0][0]=0;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=m;++j) {
				dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
				if (S[i]==T[j]) dp[i][j]=std::max(dp[i][j],dp[i-1][j-1]+1);
			}
		}for (int i=1;i<=m;++i) {
			if (dp[n][i]==n) {flag=1;}
		}if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}