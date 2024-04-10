#include<stdio.h>
int n,m,d;
long long int ans;
long long int tans;
long long int time[310];
int loc[310];
long long int score[310];
long long int dp[150100];
long long int dpb[300100];
long long int q[150100];
int qs,qe;
int main(){
	int i,j;
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<m;i++){
		scanf("%d%I64d%I64d",&loc[i],&score[i],&time[i]);
		time[i]*=d;
		ans+=score[i];
		if(i!=0){
			for(j=1;j<=n;j++){
				dpb[j]=dp[j];
			}
			if(time[i]-time[i-1]<(long long int)(n+2)){
				qs=qe=0;
				for(j=1;j<=n;j++){
					while(qs!=qe&&dpb[q[qe-1]]>dpb[j])qe--;
					q[qe]=j;
					qe++;
					if(j-((time[i]-time[i-1])*2)>q[qs])qs++;
					if(j-(time[i]-time[i-1])>0)dp[j-(time[i]-time[i-1])]=dpb[q[qs]];
				}
				for(;j-(time[i]-time[i-1])<=n;j++){
					if(j-((time[i]-time[i-1])*2)>q[qs])qs++;
					if(j-(time[i]-time[i-1])>0)dp[j-(time[i]-time[i-1])]=dpb[q[qs]];
				}
			}
			else{
				tans=dpb[1];
				for(j=2;j<=n;j++){
					if(tans>dpb[j])tans=dpb[j];
				}
				for(j=1;j<=n;j++){
					dp[j]=tans;
				}
			}
		}
		for(j=1;j<=n;j++){
			if(loc[i]>j)dp[j]+=(loc[i]-j);
			else dp[j]-=(loc[i]-j);
		}
	}
	tans=dp[1];
	for(j=2;j<=n;j++){
		if(dp[j]<tans)tans=dp[j];
	}
	printf("%I64d",ans-tans);
}