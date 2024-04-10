#include<stdio.h>
int dp[4001000];
int len;
char s[2001000];
long long int st[2001000];
long long int end[2001000];
long long int pass[2001000];
int mod=51123987;
int main(){
	int tc,i,j,k;
	long long int ans;
	scanf("%d%s",&len,s);
	j=-1;
	ans=0;
	for(i=0;i<len*2;i++){
		if(j==-1||j+dp[j]<=i){
			if(i%2==0)dp[i]=1;
			else dp[i]=0;
		}
		else{
			dp[i]=dp[2*j-i];
			if(dp[i]>j+dp[j]-i)dp[i]=j+dp[j]-i;
		}
		while(dp[i]<i&&s[(i-dp[i]-1)/2]==s[(i+dp[i]+1)/2])dp[i]+=2;
		if(j+dp[j]<i+dp[i])j=i;
		st[(i-dp[i]+1)/2]++;
		st[(i+2)/2]--;
		end[(i+1)/2]++;
		end[(i+dp[i]+1)/2]--;
	}
	for(i=0;i<len;i++){
		st[i+1]+=st[i];
		end[i+1]+=end[i];
	}
	for(i=0;i<len;i++){
		pass[i]+=st[i];
		pass[i+1]=pass[i]-end[i];
	}
	for(i=0;i<len;i++){
		ans+=((pass[i]%mod)*(st[i]%mod))%mod;
		j=((st[i]%mod)*((st[i]+1)%mod)%mod);
		if(j%2==1)j+=mod;
		j/=2;
		ans+=mod-j;
		ans%=mod;
	}
	printf("%I64d",ans);
}