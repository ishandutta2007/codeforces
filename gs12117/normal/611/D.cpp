#include<stdio.h>
int n;
char s[5010];
int sd[5010][5010];
int dp[5010][5010];
int dps[5010][5010];
int mod=1000000007;
int main(){
	int i,j,t;
	scanf("%d%s",&n,s);
	for(i=1;i<n;i++){
		t=0;
		sd[i][0]=0;
		while(s[i+sd[i][t]]==s[t+sd[i][t]])sd[i][t]++;
		sd[0][i]=sd[i][0];
		for(j=1;j<i;j++){
			if(sd[i][t]<=sd[t][j]){
				sd[i][j]=sd[i][t];
				t=j;
				while(s[i+sd[i][t]]==s[t+sd[i][t]])sd[i][t]++;
			}
			else{
				sd[i][j]=sd[t][j];
			}
			sd[j][i]=sd[i][j];
		}
	}
	for(i=0;i<n;i++){
		dp[0][i+1]=1;
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			dp[i][j]=0;
		}
		if(s[i]=='0')continue;
		for(j=i-1;j>=0;j--){
			dps[i][j]=dps[i][j+1]+dp[j][i];
			dps[i][j]%=mod;
		}
		for(j=i+1;j<=n;j++){
			if(j>i*2)t=0;
			else{
				t=i+i-j;
				if(sd[i][t]>=j-i)t++;
				else if(s[t+sd[i][t]]>s[i+sd[i][t]])t++;
			}
			dp[i][j]=dps[i][t];
		}
	}
	int ans=0;
	for(i=0;i<n;i++){
		ans+=dp[i][n];
		ans%=mod;
	}
	printf("%d",ans);
	return 0;
}