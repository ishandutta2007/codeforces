#include<stdio.h>
#include<algorithm>
using namespace std;
int c[1000];
long long C[1001][1001];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<b;i++){
		scanf("%d",c+i);
	}
	std::sort(c,c+b);
	int mod=1000000007;
	C[0][0]=1;
	for(int i=0;i<1000;i++)
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	long long ret=1;
	int n=a-b;
	for(int i=0;i<b-1;i++){
		ret=ret*C[n][c[i+1]-c[i]-1]%mod;
		n-=c[i+1]-c[i]-1;
		for(int j=0;j<c[i+1]-c[i]-2;j++)ret=ret*2%mod;
		
	}
	ret=ret*C[n][c[0]-1]%mod;
	printf("%I64d\n",ret);
}