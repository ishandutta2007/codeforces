#include<stdio.h>
int n,m;
int a,b;
int mod=1000000007;
int dp[2][52][52][3];
long long int cmb[52][52];
int q[6000][3];
int qs,qe;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	m/=50;
	for(i=0;i<=n;i++){
		cmb[i][0]=1;
		for(j=1;j<=i;j++){
			cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
			cmb[i][j]%=mod;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&j);
		if(j==50)a++;
		else b++;
	}
	dp[0][0][0][2]=1;
	qe=1;
	for(qs=0;qs<qe;qs++){
		if(q[qs][0]==0){
			for(i=q[qs][1];i<=a;i++){
				for(j=q[qs][2];j<=b;j++){
					if(i==q[qs][1]&&j==q[qs][2])continue;
					if(i-q[qs][1]+2*(j-q[qs][2])>m)continue;
					if(dp[1][i][j][0]==0){
						dp[1][i][j][0]=1;
						dp[1][i][j][1]=dp[0][q[qs][1]][q[qs][2]][1]+1;
						q[qe][0]=1;
						q[qe][1]=i;
						q[qe][2]=j;
						qe++;
					}
					if(dp[1][i][j][1]==dp[0][q[qs][1]][q[qs][2]][1]+1){
						dp[1][i][j][2]+=((dp[0][q[qs][1]][q[qs][2]][2]*cmb[a-q[qs][1]][i-q[qs][1]])%mod*cmb[b-q[qs][2]][j-q[qs][2]])%mod;
						dp[1][i][j][2]%=mod;
					}
				}
			}
		}
		else{
			for(i=0;i<=q[qs][1];i++){
				for(j=0;j<=q[qs][2];j++){
					if(i==q[qs][1]&&j==q[qs][2])continue;
					if(q[qs][1]-i+2*(q[qs][2]-j)>m)continue;
					if(dp[0][i][j][0]==0){
						dp[0][i][j][0]=1;
						dp[0][i][j][1]=dp[1][q[qs][1]][q[qs][2]][1]+1;
						q[qe][0]=0;
						q[qe][1]=i;
						q[qe][2]=j;
						qe++;
					}
					if(dp[0][i][j][1]==dp[1][q[qs][1]][q[qs][2]][1]+1){
						dp[0][i][j][2]+=((dp[1][q[qs][1]][q[qs][2]][2]*cmb[q[qs][1]][i])%mod*cmb[q[qs][2]][j])%mod;
						dp[0][i][j][2]%=mod;
					}
				}
			}
		}
	}
	if(dp[1][a][b][0]==0){
		printf("-1\n0");
	}
	else{
		printf("%d\n%d",dp[1][a][b][1],dp[1][a][b][2]);
	}
}