#include<stdio.h>
int n;
int a[200100];
int sup[200100];
int chk[200100];
int cnt[200100];
int mgcd[200100];
long long int ans;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		if(n%i==0){
			for(j=i;j<=n;j+=i){
				mgcd[j]=i;
			}
		}
	}
	for(i=1;i<n;i++){
		if(n%i==0){
			for(j=0;j<i;j++){
				sup[j]=0;
			}
			for(j=0;j<n;j++){
				if(a[j]>sup[j%i])sup[j%i]=a[j];
			}
			chk[0]=0;
			for(j=0;j<n;j++){
				if(a[j]==sup[j%i])chk[j]++;
				else chk[j]=0;
				if(chk[j]>n)chk[j]=n;
				chk[j+1]=chk[j];
			}
			chk[0]=chk[n];
			for(j=0;j<n;j++){
				if(a[j]==sup[j%i])chk[j]++;
				else chk[j]=0;
				if(chk[j]>n)chk[j]=n;
				chk[j+1]=chk[j];
			}
			cnt[0]=0;
			for(j=1;j<=n;j++){
				cnt[j]=cnt[j-1];
				if(mgcd[j]==i)cnt[j]++;
			}
			for(j=0;j<n;j++){
				ans+=cnt[chk[j]];
			}
		}
	}
	printf("%I64d",ans);
}