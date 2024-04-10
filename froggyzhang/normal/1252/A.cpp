#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5010
typedef long long ll;
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
ll a[N],dp[N][N],ans,q[N],l,r;
int n,m,b;
int main(){
	n=read(),m=read(),b=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n/m>b){
		puts("-1");
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=b;j++){
			dp[i][j]=-0x3f3f3f3f3f3f3f3f;
		}
	}
	dp[0][0]=0;
	for(int j=1;j<=b;j++){
		l=1,r=0;
		q[++r]=j-1;
		for(int i=j;i<=n;i++){
			while(l<=r&&q[l]<i-m)++l;
			if(l<=r)dp[i][j]=dp[q[l]][j-1]+a[i];
			while(l<=r&&dp[q[r]][j-1]<=dp[i][j-1])--r;
			q[++r]=i;
		}
	}
	for(int i=n-m+1;i<=n;i++){
		ans=max(ans,dp[i][b]);
	}
	cout<<ans<<endl;
	return 0;
}