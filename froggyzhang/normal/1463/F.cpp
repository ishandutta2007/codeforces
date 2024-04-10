#include<bits/stdc++.h>
using namespace std;
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
int n,w[55],X,Y,m,all,dp[2][1<<22],ans; 
int main(){
	n=read(),X=read(),Y=read();
	m=X+Y;
	for(int i=0;i<m;++i){
		w[i]=n/m+(i<n%m);
	}
	dp[1][0]=0;
	all=(1<<max(X,Y))-1;
	for(int i=0;i<m;++i){
		memset(dp[i&1],~0x3f,sizeof(dp[i&1]));
		#define update(x,y) x=max(x,y)
		for(int j=0;j<=all;++j){
			update(dp[i&1][(j<<1)&all],dp[(i-1)&1][j]);
			if(!((j<<1)>>X&1) && !((j<<1)>>Y&1))update(dp[i&1][((j<<1)&all)|1],dp[(i-1)&1][j]+w[i]);	
		}
	}
	for(int j=0;j<=all;++j){
		ans=max(ans,dp[(m-1)&1][j]);
	}
	printf("%d\n",ans);
	return 0;
}