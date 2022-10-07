#include<stdio.h>
int n;
long long int a[10];
long long int b[10];
int pfn[10];
int ans;
int tans;
int zrn;
void btrk(int p){
	int i;
	if(p==n){
		for(i=0;i<n;i++){
			if(b[i]==a[i]&&pfn[i]==1)tans--;
		}
		if(zrn==1){
			if(ans>tans-1){
				ans=tans-1;
			}
		}
		else{
			if(ans>tans){
				ans=tans;
			}
		}
		for(i=0;i<n;i++){
			if(b[i]==a[i]&&pfn[i]==1)tans++;
		}
	}
	else{
		tans+=pfn[p];
		zrn++;
		btrk(p+1);
		tans-=pfn[p];
		zrn--;
		for(i=0;i<n;i++){
			if(a[i]==a[p]&&i<=p)continue;
			if(b[i]%a[p]==0){
				b[i]/=a[p];
				btrk(p+1);
				b[i]*=a[p];
			}
		}
	}
}
int main(){
	int i,j;
	long long int t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		b[i]=a[i];
	}
	for(i=0;i<n;i++){
		t=a[i];
		for(j=2;(long long int)j*j<=t;j++){
			while(t%j==0){
				t/=j;
				pfn[i]++;
			}
		}
		if(t!=1){
			pfn[i]++;
		}
	}
	ans=9999999;
	tans=n+1;
	btrk(0);
	printf("%d",ans);
}