#include<stdio.h>
int n;
long long int ans;
long long int dp[200100];
int sn[200100];
long long int md[200100];
int par[200100];
int eft[200100];
int main(){
	int i,tmd;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&par[i],&eft[i]);
		par[i]--;
	}
	for(i=n-1;i>=0;i--){
		if(sn[i]%2==1){
			tmd=md[i];
			if(eft[i]>md[i]){
				dp[i]+=eft[i];
				dp[i]-=md[i];
				tmd=eft[i];
			}
		}
		else{
			dp[i]+=eft[i];
			tmd=eft[i];
		}
		if(ans<dp[i])ans=dp[i];
		if(i!=0){
			if(sn[par[i]]==0||md[par[i]]>tmd){
				md[par[i]]=tmd;
			}
			dp[par[i]]+=dp[i];
			sn[par[i]]++;
		}
	}
	printf("%I64d",ans);
}