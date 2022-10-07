#include<stdio.h>
int n,q;
long long int v[100100];
int c[100100];
long long int dp[100100];
long long int ans,bns,t;
int ansk;
long long int a,b;
int main(){
	int i,j;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%I64d",&v[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<q;i++){
		scanf("%I64d%I64d",&a,&b);
		for(j=0;j<=n;j++){
			dp[j]=-99999999999999LL;
		}
		ans=0;
		bns=0;
		for(j=0;j<n;j++){
			t=dp[c[j]]+a*v[j];
			if(c[j]!=ansk&&t<ans+b*v[j])t=ans+b*v[j];
			if(c[j]==ansk){
				if(t<bns+b*v[j])t=bns+b*v[j];
			}
			if(t>dp[c[j]])dp[c[j]]=t;
			if(t>ans){
				if(c[j]!=ansk){
					bns=ans;
				}
				ans=t;
				ansk=c[j];
			}
			if(c[j]!=ansk&&t>bns){
				bns=t;
			}
		}
		printf("%I64d\n",ans);
	}
}