#include<stdio.h>
long long int p,q;
char a[1010];
int al;
int b[5000];
int bl;
int nb[5000];
int nbl;
long long int c[5000];
int cl;
long long int mod=1000000007;
long long int dp[4][5000];
long long int ndp[4][5000];
long long int ans;
int main(){
	long long int i,j;
	scanf("%I64d%I64d",&p,&q);
	scanf("%s",a);
	for(al=0;a[al];al++);
	for(i=0;i<al;i++){
		b[i]=a[al-1-i]-'0';
	}
	bl=al;
	for(cl=0;bl;cl++){
		j=0;
		nbl=0;
		for(i=bl-1;i>=0;i--){
			j*=10;
			j+=b[i];
			nb[i]=j/p;
			if(j>=p){
				if(nbl==0)nbl=i+1;
				j%=p;
			}
		}
		c[cl]=j;
		bl=nbl;
		for(i=0;i<bl;i++){
			b[i]=nb[i];
		}
	}
	dp[0][0]=1;
	dp[2][0]=1;
	for(i=0;i<cl;i++){
		for(j=0;j<=i+1;j++){
			ndp[0][j]=0;
			ndp[1][j]=0;
			ndp[2][j]=0;
			ndp[3][j]=0;
		}
		for(j=0;j<=i;j++){
			ndp[0][j]+=((p*(p+1)/2)%mod)*dp[0][j];
			ndp[0][j]%=mod;
			ndp[1][j+1]+=((p*(p-1)/2)%mod)*dp[0][j];
			ndp[1][j+1]%=mod;
			ndp[0][j]+=((p*(p-1)/2)%mod)*dp[1][j];
			ndp[0][j]%=mod;
			ndp[1][j+1]+=((p*(p+1)/2)%mod)*dp[1][j];
			ndp[1][j+1]%=mod;
			ndp[2][j]+=((c[i]*(c[i]+1)/2)%mod)*dp[0][j];
			ndp[2][j]%=mod;
			ndp[3][j+1]+=((p*c[i]-(c[i]*(c[i]+1)/2))%mod)*dp[0][j];
			ndp[3][j+1]%=mod;
			ndp[2][j]+=((c[i]*(c[i]-1)/2)%mod)*dp[1][j];
			ndp[2][j]%=mod;
			ndp[3][j+1]+=((p*c[i]-(c[i]*(c[i]-1)/2))%mod)*dp[1][j];
			ndp[3][j+1]%=mod;
			ndp[2][j]+=(c[i]+1)*dp[2][j];
			ndp[2][j]%=mod;
			ndp[3][j+1]+=(p-1-c[i])*dp[2][j];
			ndp[3][j+1]%=mod;
			ndp[2][j]+=(c[i])*dp[3][j];
			ndp[2][j]%=mod;
			ndp[3][j+1]+=(p-c[i])*dp[3][j];
			ndp[3][j+1]%=mod;
		}
		for(j=0;j<=i+1;j++){
			dp[0][j]=ndp[0][j];
			dp[1][j]=ndp[1][j];
			dp[2][j]=ndp[2][j];
			dp[3][j]=ndp[3][j];
		}
	}
	ans=0;
	for(i=q;i<=cl;i++){
		ans+=dp[2][i];
		ans%=mod;
	}
	printf("%I64d",ans);
}