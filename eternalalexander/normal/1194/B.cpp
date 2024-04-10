#include <bits/stdc++.h>
#define maxn 50005
int n,m,t;
char s[100005];
std::vector<char>G[100005];
std::vector<int> suml[maxn],sumr[maxn],sumu[maxn],sumd[maxn];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i) {
			scanf("%s",s+1);
			for (int j=0;j<=m;++j) {
				G[i].push_back(s[j]);
				suml[i].push_back(0);
				sumr[i].push_back(0);
				sumu[i].push_back(0);
				sumd[i].push_back(0);
			}
		}for (int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if (i!=1)suml[i][j]=suml[i-1][j]+(G[i][j]=='*');
				else suml[i][j]=(G[i][j]=='*');
				if (j!=1) sumu[i][j]=sumu[i][j-1]+(G[i][j]=='*');
				else sumu[i][j]=(G[i][j]=='*');
			}
		}int ans=0;
		for (int i=n;i>=1;--i){
			for(int j=m;j>=1;--j){
				if (i!=n)sumr[i][j]=sumr[i+1][j]+(G[i][j]=='*');
				else sumr[i][j]=(G[i][j]=='*');
				if (j!=m) sumd[i][j]=sumd[i][j+1]+(G[i][j]=='*');
				else sumd[i][j]=(G[i][j]=='*');
				ans=std::max(ans,sumu[i][j]+sumd[i][j]+suml[i][j]+sumr[i][j]-(G[i][j]=='*'?3:0));
			}
		}printf("%d\n",n+m-1-ans);
		for (int i=1;i<=n;++i){
			for (int j=0;j<=m;++j){
				suml[i].pop_back();
				sumr[i].pop_back();
				sumu[i].pop_back();
				sumd[i].pop_back();
				G[i].pop_back();
			}
		}
	}
	return 0;
}