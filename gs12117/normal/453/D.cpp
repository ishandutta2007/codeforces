#include<stdio.h>
int m;
long long int time,p;
long long int dp[22];
long long int ndp[22];
long long int a[25];
long long int e[1<<20];
long long int ed[1<<20][21];
long long int ans[1<<20];
int cmb[25][25];
int main(){
	int i,j,k,l;
	cmb[0][0]=1;
	for(i=0;i<22;i++){
		for(j=0;j<=i;j++){
			cmb[i+1][j]+=cmb[i][j];
			cmb[i+1][j+1]+=cmb[i][j];
		}
	}
	scanf("%d%I64d%I64d",&m,&time,&p);
	for(i=0;i<(1<<m);i++){
		scanf("%I64d",&e[i]);
	}
	for(i=0;i<=m;i++){
		scanf("%I64d",&a[i]);
	}
	for(i=0;i<=m;i++){
		dp[i]=0;
	}
	dp[0]=1;
	for(i=62;i>=0;i--){
		for(j=0;j<=m;j++){
			ndp[j]=0;
		}
		for(j=0;j<=m;j++){
			for(k=0;k<=m;k++){
				for(l=0;l<=k;l++){
					if(j<l||j-l>m-k)continue;
					ndp[j]+=((dp[k]*dp[k-l+j-l])%p)*cmb[j][l]*cmb[m-j][k-l];
					ndp[j]%=p;
				}
			}
		}
		for(j=0;j<=m;j++){
			dp[j]=ndp[j]%p;
		}
		if((time>>i)&1){
			for(j=0;j<=m;j++){
				ndp[j]=0;
			}
			for(j=0;j<=m;j++){
				for(k=0;k<=m;k++){
					for(l=0;l<=k;l++){
						if(j<l||j-l>m-k)continue;
						ndp[j]+=((dp[k]*a[k-l+j-l])%p)*cmb[j][l]*cmb[m-j][k-l];
						ndp[j]%=p;
					}
				}
			}
			for(j=0;j<=m;j++){
				dp[j]=ndp[j]%p;
			}
		}
	}
	int t;
	for(i=0;i<(1<<m);i++){
		ed[i][0]=e[i];
		for(j=0;j<m;j++){
			ed[i][1]+=e[i^(1<<j)];
		}
	}
	for(i=2;i<=m;i++){
		for(j=0;j<(1<<m);j++){
			for(k=0;k<m;k++){
				ed[j][i]+=ed[j^(1<<k)][i-1];
			}
			ed[j][i]-=ed[j][i-2]*(m-i+2);
			ed[j][i]/=i;
		}
	}
	for(i=0;i<(1<<m);i++){
		for(j=0;j<=m;j++){
			ans[i]+=(ed[i][j]%p)*dp[j];
			ans[i]%=p;
		}
		printf("%I64d\n",ans[i]);
	}
}