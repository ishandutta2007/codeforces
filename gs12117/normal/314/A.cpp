#include<stdio.h>
int n;
long long int k;
long long int a[200100];
int out[200100];
int onum;
long long int sum;
int main(){
	int i;
	scanf("%d%I64d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		if(sum-((n-i-1)*a[i])*(i-onum)<k){
			out[i]=1;
			onum++;
			printf("%d\n",i+1);
		}
		else{
			sum+=a[i]*(i-onum);
		}
	}
}