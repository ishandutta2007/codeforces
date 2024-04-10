#include<stdio.h>
const int n=7;
const int msiz=1<<n;
const int mod=1000000007;
int a[n];
int ans[msiz];
long long int tans[msiz];
struct matrix{
	long long int cont[msiz][msiz];
	matrix operator*(const matrix&r)const{
		matrix p;
		int i,j,k;
		for(i=0;i<msiz;i++){
			for(j=0;j<=i;j++){
				p.cont[i][j]=0;
				for(k=0;k<msiz;k+=4){
					p.cont[i][j]+=cont[i][k]*r.cont[k][j]+cont[i][k+1]*r.cont[k+1][j]+cont[i][k+2]*r.cont[k+2][j]+cont[i][k+3]*r.cont[k+3][j];
					p.cont[i][j]%=mod;
				}
			}
		}
		for(i=0;i<msiz;i++){
			for(j=i+1;j<msiz;j++){
				p.cont[i][j]=p.cont[j][i];
			}
		}
		return p;
	}
};
matrix q[4];
matrix pwr(int x){
	matrix res;
	if(x==0){
		int i,j;
		for(i=0;i<msiz;i++){
			for(j=0;j<msiz;j++){
				if(i==j)res.cont[i][j]=1;
				else res.cont[i][j]=0;
			}
		}
		return res;
	}
	res=pwr(x/4);
	res=res*res;
	res=res*res;
	if(x%4!=0)res=res*q[x%4];
	return res;
}
int main(){
	int i,j,k,l;
	matrix p;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<msiz;i++){
		ans[i]=0;
	}
	ans[0]=1;
	for(i=n;i>0;i--){
		for(j=0;j<msiz;j++){
			for(k=0;k<msiz;k++){
				p.cont[j][k]=0;
			}
		}
		for(j=0;j<(1<<i);j++){
			for(k=0;k<(1<<i);k++){
				for(l=0;l<(1<<(i-1));l++){
					if((j|k|l|(l<<1))==(1<<i)-1)p.cont[j][k]++;
				}
			}
		}
		q[1]=p;
		q[2]=p*p;
		q[3]=q[2]*p;
		p=pwr(a[i-1]);
		for(j=0;j<msiz;j++){
			tans[j]=0;
			for(k=0;k<msiz;k++){
				tans[j]+=ans[k]*p.cont[j][k];
				tans[j]%=mod;
			}
		}
		for(j=0;j<msiz;j++)ans[j]=tans[j];
	}
	printf("%d",ans[0]);
}