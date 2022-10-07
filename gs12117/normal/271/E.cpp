#include<stdio.h>
int a[100100];
int n,m;
int b[100100];
int bn;
long long int ans;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int main(){
	int i,tgcd;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	tgcd=a[0];
	while(tgcd%2==0)tgcd/=2;
	for(i=1;i<n;i++){
		tgcd=gcd(a[i],tgcd);
	}
	for(i=1;i*i<=tgcd;i++){
		if(tgcd%i==0){
			b[bn]=i;
			bn++;
			if(i*i!=tgcd){
				b[bn]=tgcd/i;
				bn++;
			}
		}
	}
	for(i=0;i<bn;i++){
		if(b[i]*2<m){
			b[bn]=b[i]*2;
			bn++;
		}
	}
	for(i=0;i<bn;i++){
		if(b[i]<m){
			ans+=m-b[i];
		}
	}
	printf("%I64d",ans);
}