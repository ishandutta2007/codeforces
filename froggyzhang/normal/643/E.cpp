#include<bits/stdc++.h>
using namespace std;
#define N 500050
#define M 65
const int B=60;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
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
int Q,n,f[N];
double dp[N][M];
int main(){
	Q=read();
	n=1;
	for(int i=1;i<=B;++i)dp[n][i]=1;
	while(Q--){
		int opt=read(),x=read();
		if(opt==1){
			++n;
			f[n]=x;
			for(int i=1;i<=B;++i){
				dp[n][i]=1;	
			}
			dp[n][0]=0;
			double las=1;
			int y=n;
			for(int i=1;x&&i<=B;y=x,x=f[x],++i){
				double tmp=(1+dp[x][i])/2.0;
				dp[x][i]/=las;
				dp[x][i]*=(1+dp[y][i-1])/2.0;
				las=tmp;
			}
		}
		else{
			double ans=B;
			for(int i=1;i<=B;++i)ans-=dp[x][i];
			printf("%.10lf\n",ans);
		}	
	}
	return 0;
}