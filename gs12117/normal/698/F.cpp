#include<stdio.h>
int n;
int ers[1001000];
int a[1001000];
long long int ans;
const int mod=1000000007;
int gp[1001000];
int gn;
int sn[1001000];
int gdn[1001000];
int ps[1001000];
int chk[1001000];
int dp[1001000];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(ers[i]!=0)continue;
		for(j=i;j<=n;j+=i){
			ers[j]=i;
		}
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=1;
	if(n<=3){
		j=0;
		for(i=1;i<=n;i++){
			if(a[i]==0){
				j++;
			}
		}
		for(i=1;i<=j;i++){
			ans*=i;
		}
	}
	else{
		for(i=2;i<=n;i++){
			if(ers[i]==i){
				if(n/i!=sn[gn]){
					gn++;
					sn[gn]=n/i;
				}
				gp[i]=gn;
				gdn[gn]++;
			}
		}
		ers[1]=1;
		gp[1]=gn;
		gdn[gn]++;
		gn++;
		for(i=1;i<=n;i++){
			if(a[i]!=0){
				j=i;
				k=a[i];
				if(j==1||k==1){
					if(gp[ers[j]]!=gp[ers[k]])ans=0;
					else{
						if(ps[ers[j]]==0){
							gdn[gp[ers[j]]]--;
							if(chk[ers[k]]==1){
								ans=0;
							}
							chk[ers[k]]=1;
							ps[ers[j]]=ers[k];
						}
						else if(ps[ers[j]]!=ers[k]){
							ans=0;
						}
					}
				}
				else{
					while(j>1&&k>1){
						if(gp[ers[j]]!=gp[ers[k]])ans=0;
						else{
							if(ps[ers[j]]==0){
								gdn[gp[ers[j]]]--;
								if(chk[ers[k]]==1){
									ans=0;
								}
								chk[ers[k]]=1;
								ps[ers[j]]=ers[k];
							}
							else if(ps[ers[j]]!=ers[k]){
								ans=0;
							}
						}
						while(ers[j/ers[j]]==ers[j])j/=ers[j];
						j/=ers[j];
						while(ers[k/ers[k]]==ers[k])k/=ers[k];
						k/=ers[k];
					}
					if(j>1||k>1)ans=0;
				}
			}
		}
		for(i=0;i<=gn;i++){
			for(j=1;j<=gdn[i];j++){
				ans*=j;
				ans%=mod;
			}
		}
		for(i=2;i<=n;i++){
			j=i;
			k=1;
			while(j!=1){
				if(ers[j/ers[j]]!=ers[j])k*=ers[j];
				j/=ers[j];
			}
			if(k==0)continue;
			if(a[i]==0)dp[k]++;
		}
		for(i=0;i<=n;i++){
			for(j=1;j<=dp[i];j++){
				ans*=j;
				ans%=mod;
			}
		}
	}
	printf("%I64d",ans);
	return 0;
}