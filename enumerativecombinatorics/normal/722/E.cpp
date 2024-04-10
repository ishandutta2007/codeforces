#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
long long inv[210000];
int T=22;
long long fact[210000];
long long finv[210000];
inline long long C(int a,int b){
	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
int row[2100];
int col[2100];
pair<int,int>p[2100];
int x[2100];
int y[2100];
long long dp[2100][24];
int f[25];
long long dp2[25];
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	finv[0]=fact[0]=1;
	inv[1]=1;
	for(int i=2;i<210000;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<210000;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int sz=0;
	for(int i=0;i<c;i++){
		scanf("%d%d",row+i,col+i);
		row[i]--;col[i]--;
		if(row[i]==0&&col[i]==0){
			d=(d+1)/2;continue;
		}
		if(row[i]==a-1&&col[i]==b-1){
			d=(d+1)/2;continue;
		}
		
		p[sz++]=make_pair(row[i],col[i]);
	}
	long long ret=0;
	std::sort(p,p+sz);
	for(int i=0;i<sz;i++){
		x[i+1]=p[i].first;
		y[i+1]=p[i].second;
	}
	x[sz+1]=a-1;
	y[sz+1]=b-1;
	int n=sz+2;
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=T;j++){
			long long ks=C(x[i]+y[i],x[i]);
			for(int k=0;k<i;k++){
				if(x[i]<x[k]||y[i]<y[k])continue;
				ks=(ks-dp[k][j]*C(y[i]-y[k]+x[i]-x[k],y[i]-y[k])%mod)%mod;
			}
			for(int k=0;k<j;k++)ks=(ks+mod-dp[i][k])%mod;
			dp[i][j]=ks;
		}
	}
	f[1]=d;
	for(int i=2;i<25;i++){
		f[i]=(f[i-1]+1)/2;
	}
	long long cur=C(a+b-2,a-1);
	for(int i=0;i<22;i++){
		ret=(ret+dp[n-1][i]*f[i])%mod;
		cur=(cur+mod-dp[n-1][i])%mod;
	}
	ret=(ret+cur)%mod;
	ret=ret*pw(C(a+b-2,a-1),mod-2)%mod;
	printf("%I64d\n",ret);
}