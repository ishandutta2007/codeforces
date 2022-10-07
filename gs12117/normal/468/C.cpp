#include<stdio.h>
long long int n,tn;
long long int f(long long int x){
	long long int i,j,t,ans;
	if(x<10LL)return x*(x+1)/2;
	t=x;
	j=1;
	for(i=0;;i++){
		t/=10;
		if(t==0LL){
			break;
		}
		j*=10;
	}
	ans=f(x%j);
	ans+=(x/j)*i*45*(j/10);
	ans+=j*(((x/j)*((x/j)-1))/2);
	ans+=(x/j)*(x%j+1);
	return ans;
}
int main(){
	long long int i,j;
	scanf("%I64d",&n);
	tn=n;
	start:
	j=1;
	for(i=54;i>=0;i--){
		j+=(1LL<<i);
		if(f(j)>n)j-=(1LL<<i);
	}
	i=0;
	while(1){
		if(f(j)-f(i)>n){
			i++;
		}
		else if(f(j)-f(i)<n){
			j++;
		}
		else if(i>10000){
			n+=tn;
			goto start;
		}
		else{
			printf("%I64d %I64d",i+1,j);
			return 0;
		}
	}
}