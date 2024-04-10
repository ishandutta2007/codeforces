#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 505
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll pre;
int a[N],b[N],dp[N][N],n,m,tot,ans; 
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		if(a[i]>m)pre+=a[i]/m-1,a[i]=a[i]%m+m;
		if(b[i]>m)pre+=b[i]/m-1,b[i]=b[i]%m+m;
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=tot=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			if(dp[i-1][j]<0)continue;
			int blue=(tot-j+m)%m;
			for(int k=0;k<=a[i];++k){
				if(k+(a[i]+b[i]-k)/m*m<a[i])continue;
				dp[i][(j+k)%m]=max(dp[i][(j+k)%m],dp[i-1][j]+(j+k)/m+(a[i]+b[i]-k)/m+((a[i]+b[i]-k)%m+blue)/m);
			}
		}
		tot=(tot+a[i]+b[i])%m;
	}
	for(int i=0;i<m;++i){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans+pre<<endl;
	return 0;
}