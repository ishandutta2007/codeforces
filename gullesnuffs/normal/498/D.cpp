#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int q;
char type[5];
vector<int> dp[60][20];

int main(){
	scanf("%d", &n);
	for(int i=0; i < 60; ++i)
		for(int j=0; j < 20; ++j)
			dp[i][j].resize(n/(1<<j));
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
		for(int j=0; j < 60; ++j){
			if(j%a[i] == 0)
				dp[j][0][i]=2;
			else
				dp[j][0][i]=1;
		}
	}
	for(int j=1; j < 20; ++j)
	for(int k=0; k < 60; ++k)
		for(int i=0; (i+(1<<j)) <= n; ++i){
			if(i%(1<<j))
				continue;
			int I=i/(1<<j);
			dp[k][j][I]=dp[k][j-1][2*I]+dp[(k+dp[k][j-1][2*I])%60][j-1][2*I+1];
		}
	scanf("%d", &q);
	while(q--){
		scanf("%s", type);
		int x, y;
		scanf("%d%d", &x, &y);
		if(type[0] == 'A'){
			--x;--y;
			int ans=0;
			while(x < y){
				for(int i=19; i >= 0; --i){
					if(x&((1<<i)-1))
						continue;
					if(x+(1<<i) > y)
						continue;
					ans += dp[ans%60][i][x/(1<<i)];
					x += (1<<i);
					break;
				}
			}
			printf("%d\n", ans);
		}
		else{
			--x;
			a[x]=y;
			for(int j=0; j < 60; ++j){
				if(j%y == 0)
					dp[j][0][x]=2;
				else
					dp[j][0][x]=1;
			}
			for(int i=1; i < 20; ++i){
				if(x&(1<<(i-1)))
					x -= (1<<(i-1));
				int I=x/(1<<i);
				if((I+1)*(1<<i) > n)
					break;
				for(int k=0; k < 60; ++k){
				
					dp[k][i][I]=dp[k][i-1][2*I]+dp[(k+dp[k][i-1][2*I])%60][i-1][2*I+1];
				}
			}
		}
	}
}