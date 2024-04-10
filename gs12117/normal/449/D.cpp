#include<stdio.h>
int n;
int a[1001000];
int b[1<<20];
int mod=1000000007;
int ans;
int mpw(int x,int y){
	if(y==0)return 1;
	long long int r=mpw(x,y/2);
	r*=r;
	r%=mod;
	if(y%2==0)return r;
	r*=x;
	r%=mod;
	return r;
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(i=19;i>=0;i--){
		for(j=0;j<(1<<20);j++){
			if((j&(1<<i))==0){
				b[j]+=b[j+(1<<i)];
			}
		}
	}
	for(i=0;i<(1<<20);i++){
		k=0;
		for(j=0;j<20;j++){
			if(i&(1<<j)){
				k^=1;
			}
		}
		if(k){
			ans+=mod-mpw(2,b[i]);
		}
		else{
			ans+=mpw(2,b[i]);
		}
		ans%=mod;
	}
	printf("%d",ans);
}