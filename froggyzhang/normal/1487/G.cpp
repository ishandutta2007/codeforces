#include<bits/stdc++.h>
using namespace std;
#define N 404
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,c[27],ans;
int Solve2(){
	static int dp[2][N][N][3][3],t[N][N];
	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			++dp[0][(i==1)+(j==1)][(i==2)+(j==2)][i>2?0:i][j>2?0:j];
		}
	}
	for(int i=3;i<=n;++i){
		memset(dp[i&1],0,sizeof(dp[i&1]));
		for(int x=0;x<i;++x){
			for(int y=0;x+y<i;++y){
				for(int j=0;j<3;++j){
					for(int k=0;k<3;++k){
						for(int p=0;p<3;++p){
							if(j&&p&&j==p)continue;
							int w=dp[(i-1)&1][x][y][j][k];
							if(!w)continue;
							#define update(x,y) x=(x+y)%mod
							update(dp[i&1][x+(p==1)][y+(p==2)][k][p],1LL*w*(p?1:24-(!j)));
						}
					}
				}
			}
		}
	}
	for(int i=n;i>=0;--i){
		for(int j=n;j>=0;--j){
			t[i][j]=((t[i+1][j]+t[i][j+1])%mod-t[i+1][j+1]+mod)%mod;
			for(int x=0;x<3;++x){
				for(int y=0;y<3;++y){
					t[i][j]=(t[i][j]+dp[n&1][i][j][x][y])%mod;
				}
			}
		}
	}
	int tot=0;
	for(int i=1;i<=26;++i){
		for(int j=i+1;j<=26;++j){
			tot=(tot+t[c[i]+1][c[j]+1])%mod;
		}
	}
	return tot;
}
int Solve1(){
	static int dp[N][N][2][2],t[N];
	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			++dp[2][(i==1)+(j==1)][i==1][j==1];
		}
	}
	for(int i=3;i<=n;++i){
		for(int z=0;z<i;++z){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					for(int p=0;p<2;++p){
						if(j&&p)continue;
						int w=dp[i-1][z][j][k];
						if(!w)continue;
						#define update(x,y) x=(x+y)%mod
						update(dp[i][z+p][k][p],1LL*w*(p?1:25-(!j)));
					}
				}
			}
		}
	}
	for(int i=n;i>=0;--i){
		t[i]=t[i+1];
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				t[i]=(t[i]+dp[n][i][j][k])%mod;
			}
		}
	}
	int tot=0;
	for(int i=1;i<=26;++i){
		tot=(tot+t[c[i]+1])%mod;
	}
	return tot;
}
int main(){
	n=read();
	for(int i=1;i<=26;++i)c[i]=read();
	int ans=26*26;
	for(int i=3;i<=n;++i){
		ans=25LL*ans%mod;
	}
	ans=(ans-Solve1()+mod)%mod;
	ans=(ans+Solve2())%mod;
	printf("%d\n",ans);
	return 0;
}