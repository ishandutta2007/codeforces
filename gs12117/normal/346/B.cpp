#include<stdio.h>
char sa[110];
char sb[110];
char sc[110];
int sal,sbl,scl;
int dp[110][110][110];
int bdp[110][110][110][4];
int ff[110];
char out[110];
int main(){
	int i,j,k,l,t,ti,tj,tk;
	scanf("%s%s%s",sa,sb,sc);
	for(sal=0;sa[sal];sal++);
	for(sbl=0;sb[sbl];sbl++);
	for(scl=0;sc[scl];scl++);
	for(i=0;i<scl;i++){
		for(j=i-1;j>=0;j--){
			for(k=0;k<j;k++){
				if(sc[k]!=sc[i-j+k])break;
			}
			if(k==j){
				ff[i]=j;
				break;
			}
		}
	}
	for(i=0;i<=sal;i++){
		for(j=0;j<=sbl;j++){
			for(k=1;k<=scl;k++){
				dp[i][j][k]=-9999999;
			}
			for(k=0;k<=scl;k++){
				bdp[i][j][k][0]=-9999999;
			}
		}
	}
	for(i=0;i<=sal;i++){
		for(j=0;j<=sbl;j++){
			for(k=0;k<scl;k++){
				if(dp[i+1][j][k]<dp[i][j][k]){
					dp[i+1][j][k]=dp[i][j][k];
					bdp[i+1][j][k][0]=bdp[i][j][k][0];
					bdp[i+1][j][k][1]=bdp[i][j][k][1];
					bdp[i+1][j][k][2]=bdp[i][j][k][2];
				}
				if(dp[i][j+1][k]<dp[i][j][k]){
					dp[i][j+1][k]=dp[i][j][k];
					bdp[i][j+1][k][0]=bdp[i][j][k][0];
					bdp[i][j+1][k][1]=bdp[i][j][k][1];
					bdp[i][j+1][k][2]=bdp[i][j][k][2];
				}
			}
			if(i!=sal&&j!=sbl&&sa[i]==sb[j]){
				for(k=0;k<scl;k++){
					t=0;
					for(l=k;l!=0;l=ff[l]){
						if(sc[l]==sa[i]){
							t=l;
							break;
						}
					}
					if(sc[t]==sa[i])t++;
					if(dp[i+1][j+1][t]<dp[i][j][k]+1){
						dp[i+1][j+1][t]=dp[i][j][k]+1;
						bdp[i+1][j+1][t][0]=i;
						bdp[i+1][j+1][t][1]=j;
						bdp[i+1][j+1][t][2]=k;
					}
				}
			}
		}
	}
	t=0;
	for(i=1;i<scl;i++){
		if(dp[sal][sbl][i]>dp[sal][sbl][t])t=i;
	}
	if(dp[sal][sbl][t]==0)printf("0");
	else{
		i=sal;
		j=sbl;
		k=t;
		ti=bdp[i][j][k][0];
		tj=bdp[i][j][k][1];
		tk=bdp[i][j][k][2];
		i=ti;
		j=tj;
		k=tk;
		while(dp[i][j][k]>=0){
			out[dp[i][j][k]]=sa[i];
			if(dp[i][j][k]==0)break;
			ti=bdp[i][j][k][0];
			tj=bdp[i][j][k][1];
			tk=bdp[i][j][k][2];
			i=ti;
			j=tj;
			k=tk;
		}
		printf("%s",out);
	}
}