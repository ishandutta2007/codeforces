#include<stdio.h>
int n;
int m;
int mod=1000000007;
int uft[100100][2];
int uftf(int x){
	if(x==uft[x][0])return x;
	int t=uftf(uft[x][0]);
	uft[x][1]=uft[x][1]^uft[uft[x][0]][1];
	uft[x][0]=t;
	return t;
}
int main(){
	int i,a,b,c,p;
	scanf("%d%d",&n,&m);
	p=n-1;
	for(i=1;i<=n;i++){
		uft[i][0]=i;
		uft[i][1]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		c^=1;
		if(uftf(a)!=uftf(b)){
			p--;
			uft[uft[a][0]][1]=uft[a][1]^uft[b][1]^c;
			uft[uft[a][0]][0]=uft[b][0];
		}
		else{
			if((uft[a][1]^uft[b][1])!=c){
				printf("0");
				return 0;
			}
		}
	}
	long long int ans=1;
	for(i=0;i<p;i++){
		ans*=2;
		ans%=mod;
	}
	printf("%I64d",ans);
}