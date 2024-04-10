#include<stdio.h>
long long int n;
int a[101000];
int dans[101000];
long long int ans;
int findans(long long int d){
	if(d<100000){
		ans=dans[d];
		return a[ans];
	}
	long long int i,j,k,ta,tb;
	for(i=0;i*i*i<=d;i++);
	i--;
	j=findans(d-(i*i*i));
	ta=ans+i*i*i;
	k=findans(3*i*i-3*i+1);
	tb=ans+i*i*i-(3*i*i-3*i+1);
	if(j>=k){
		ans=ta;
	}
	else{
		j=k;
		ans=tb;
	}
	return j+1;
}
int main(){
	int i,j,k,t;
	dans[0]=0;
	for(i=0;i<100100;i++){
		t=i;
		for(j=0;t!=0;j++){
			for(k=0;k*k*k<=t;k++);
			k--;
			t-=k*k*k;
		}
		a[i]=j;
		if(a[dans[i]]<=a[i]){
			dans[i]=i;
		}
		dans[i+1]=dans[i];
	}
	scanf("%I64d",&n);
	int x=findans(n);
	printf("%d %I64d",x,ans);
return 0;
}