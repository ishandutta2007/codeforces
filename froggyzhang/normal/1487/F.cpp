#include<bits/stdc++.h>
using namespace std;
#define N 55
const int inf=0x3f3f3f3f;
const int B=500;
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
char s[N];
int a[N],len,ans;
int dp[N][1005][1005];
int main(){
	scanf("%s",s+1);
	len=strlen(s+1)+4;
	for(int i=1;i<=len-4;++i){
		a[i+4]=s[i]-'0';
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][B][B]=0;
	ans=inf;
	for(int i=1;i<=len;++i){
		for(int j=-B;j<=B;++j){
			for(int k=-i*6;k<=i*6;++k){
				int w=dp[i-1][j+B][k+B];
				if(w>=inf)continue;
				#define update(x,y) x=min(x,y)
				for(int p=-6;p<=6;++p){
					int x=j*10+k+p-a[i];
					if(x>=-B&&x<=B)update(dp[i][B+x][B+k+p],w+(len-i+1)*abs(p));
				}
			}
		}
	}
	for(int j=-B;j<=B;++j)
		ans=min(ans,dp[len][B][B+j]);
	printf("%d\n",ans);
	return 0;
}