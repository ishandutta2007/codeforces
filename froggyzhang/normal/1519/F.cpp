#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
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
int n,a[7],b[7],m,pw[7],c[7][7];
int dp[7][5][23333];
vector<int> B;
int Get(const vector<int> &A){
	int ans=0;
	for(int i=0;i<m;++i)ans+=pw[i]*A[i];
	return ans;	
}
vector<int> Trans(int x){
	vector<int> t;
	for(int i=0;i<m;++i)t.push_back(x%5),x/=5;
	return t;	
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<m;++i)b[i]=read(),B.push_back(b[i]);
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			c[i][j]=read();
		}
	}
	pw[0]=1;
	for(int i=1;i<=m;++i)pw[i]=pw[i-1]*5;
	memset(dp,0x3f,sizeof(dp));
	int lim;
	dp[0][0][lim=Get(B)]=0;
	for(int i=1;i<=n;++i){
		memcpy(dp[i][0],dp[i-1][a[i-1]],sizeof(dp[i][0]));
		for(int j=1;j<=a[i];++j){
			for(int k=1;k<=j;++k){
				for(int s=0;s<=lim;++s){
					int w=dp[i][j-k][s];
					if(w<inf){
						vector<int> A=Trans(s);
						for(int p=0;p<m;++p){
							if(A[p]>=k){
								vector<int> C=A;
								C[p]-=k;
								int u=Get(C);
								dp[i][j][u]=min(dp[i][j][u],w+c[i][p]);
							}	
						}
					}
				}	
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=lim;++i){
		ans=min(ans,dp[n][a[n]][i]);
	}
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}