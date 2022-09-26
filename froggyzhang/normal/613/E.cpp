#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int base=233;
#define N 2020
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
int n,m,pre[2][N],suf[2][N];
int h[N],c[N];
char s[2][N],t[N];
int Solve_1(){
	int ans=0;
	for(int i=0;i<=1;++i)
		for(int j=1;j<=n;++j)
			ans+=s[i][j]==t[1];
	return ans;
}
int Solve_2(){
	int ans=0;
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			ans+=s[i][j]==t[1]&&s[i^1][j]==t[2];
			ans+=s[i][j]==t[1]&&s[i][j+1]==t[2];
			ans+=s[i][j]==t[1]&&s[i][j-1]==t[2];
		}
	}
	return ans;
}
int splice(int h1,int h2,int x){
	return (h2+1LL*h1*c[x])%mod;
}
int Get1(int l,int r,int i){
	return (pre[i][r]-1LL*pre[i][l-1]*c[r-l+1]%mod+mod)%mod;
}
int Get2(int l,int r,int i){
	return (suf[i][l]-1LL*suf[i][r+1]*c[r-l+1]%mod+mod)%mod;
}
int qwq,f[2][N][N],g[2][N][N];
int Solve(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for(int i=1;i<=m;++i){
		h[i]=(1LL*h[i-1]*base+(t[i]-'a'+1))%mod;
	}
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			for(int k=j;k>=1;--k){
				int len=2*(j-k+1);
				if(len>m)continue;
				int Ha=Get1(k,j,i);
				int Hb=Get2(k,j,i^1);
				int Ht=h[len];
				if(splice(Hb,Ha,j-k+1)==Ht){
					if(len==m){
						++qwq;
					}
					else{
						g[i][j][len]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			g[i][j][1]=(s[i][j]==t[1]);
		}
	}
	#define update(x,y) x=(x+y)%mod
	for(int k=1;k<m;++k){
		for(int i=0;i<=1;++i){
			for(int j=1;j<=n;++j){
				if(f[i][j][k]){
					if(s[i][j+1]==t[k+1])update(f[i][j+1][k+1],f[i][j][k]);
					if(s[i^1][j]==t[k+1])update(g[i^1][j][k+1],f[i][j][k]);
				}
				if(g[i][j][k]){
					if(s[i][j+1]==t[k+1])update(f[i][j+1][k+1],g[i][j][k]);
				}
			}
		}
	}
	for(int i=m;i>=1;--i){
		h[i]=(1LL*h[i+1]*base%mod+(t[i]-'a'+1))%mod;
	}
	int ans=0;
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			if(s[i][j]==t[m]){
				ans=(ans+(f[i][j-1][m-1]+g[i][j-1][m-1])%mod)%mod;
			}
			for(int k=j;k<=n;++k){
				int len=2*(k-j+1)%mod;
				if(len>m)continue;
				int Ha=Get1(j,k,i^1);
				int Hb=Get2(j,k,i);
				int Ht=h[m-len+1];
				if(splice(Ha,Hb,k-j+1)==Ht){
					if(len==m){
						++qwq;
					}
					else{
						ans=(ans+(f[i][j-1][m-len]+g[i][j-1][m-len])%mod)%mod;
					}
				}
			}
		}
	}
	return ans;
}
int main(){
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	scanf("%s",t+1);
	n=strlen(s[0]+1);
	m=strlen(t+1);
	if(m==1)return !printf("%d\n",Solve_1());
	if(m==2)return !printf("%d\n",Solve_2());
	c[0]=1;
	for(int i=1;i<=n;++i){
		c[i]=1LL*c[i-1]*base%mod;
	}
	for(int i=0;i<=1;++i){
		for(int j=1;j<=n;++j){
			pre[i][j]=(1LL*pre[i][j-1]*base+(s[i][j]-'a'+1))%mod;
		}
		for(int j=n;j>=1;--j){
			suf[i][j]=(1LL*suf[i][j+1]*base+(s[i][j]-'a'+1))%mod;
		}
	}
	int ans=Solve();
	reverse(t+1,t+m+1);
	ans=(ans+Solve())%mod;
	ans=(ans+(qwq>>1))%mod;
	printf("%d\n",ans);
	return 0;
}