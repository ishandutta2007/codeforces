#include<stdio.h>
#include<algorithm>
using namespace std;
long long C[3002][3002];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int mod=1000000007;
	C[0][0]=1;
	for(int i=0;i<3001;i++){
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	}
	printf("%d\n",(int)(C[a-1][c*2]*C[b-1][c*2]%mod));
}