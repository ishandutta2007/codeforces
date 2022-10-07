#include<stdio.h>
#include<algorithm>
long long int n,m;
long long int p;
long long int ans;
struct st{
	int x,loc;
	bool operator<(const st&r)const{
		return x<r.x;
	}
};
st a[1001000];
long long int dp[1001000];
long long int dpb[1001000];
long long int mod=1000000007;
int main(){
	int i,j,k;
	long long int t;
	scanf("%I64d%I64d%I64d",&n,&p,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i].loc=i;
	}
	std::sort(a,a+n);
	dpb[0]=1;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			dp[j]=dpb[j];
			dpb[j]=0;
		}
		k=0;
		dpb[0]=0;
		for(j=0;j<n;j++){
			if(j!=0)dpb[j]=dpb[j-1];
			while(k<n&&a[k].x==a[j].x){
				dpb[j]+=dp[k];
				dpb[j]%=mod;
				k++;
			}
			t=p/n-i;
			if(a[j].loc<p%n){
				t++;
			}
			if(t<0)t=0;
			t%=mod;
			ans+=(dpb[j]*t)%mod;
			ans%=mod;
		}
	}
	printf("%I64d",ans);
	return 0;
}