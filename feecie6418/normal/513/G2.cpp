#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,a[105];
double f[1005][105][105],s1[105][105],s2[105][105],s5[105][105],s6[105][105],s3[105][105],s4[105][105];
int main(){
	cin>>n>>K,K=min(K,1000);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[0][i][j]=(a[i]>a[j]);
	for(int i=1;i<=K;i++){
		double u=1.0l/(n*(n+1)/2);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				s1[j][k]=s1[j-1][k]+f[i-1][j][k];
				s3[j][k]=s3[j][k-1]+f[i-1][j][k];
				s5[j][k]=s5[j-1][k-1]+f[i-1][j][k];
			}
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				s2[j][k]=s2[j-1][k]+s1[j][k];
				s4[j][k]=s4[j][k-1]+s3[j][k];
				s6[j][k]=s6[j-1][k-1]+s5[j][k];
			}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				f[i][j][k]+=(j-1)*j/2*f[i-1][j][k];
				f[i][j][k]+=(n-k)*(n-k+1)/2*f[i-1][j][k];
				f[i][j][k]+=(k-j)*(k-j-1)/2*f[i-1][j][k];
				f[i][j][k]+=s2[k-1][k]-s2[k-j-1][k]-s2[j-1][k];
				f[i][j][k]+=s4[j][n]-s4[j][j+n-k]-s4[j][k-1]+s4[j][j-1];
				f[i][j][k]+=s6[n][j-k+n]-s6[n-j][n-k]-s6[k-1][j-1];
				f[i][j][k]*=u;
				f[i][k][j]=1-f[i][j][k];
			}
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=f[K][i][j];
	printf("%.15lf\n",ans);
}