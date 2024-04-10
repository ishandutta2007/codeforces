#include<stdio.h>
#include<algorithm>
using namespace std;
int sum[42][42][42][42];
char str[50][50];
int t[64][64];
int sum2[42][42][42][42];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%s",str[i]);
		for(int j=0;j<b;j++)t[i+1][j+1]=str[i][j]-'0';
	}
	for(int i=0;i<=a;i++)
		for(int j=1;j<=b;j++)
			t[i][j]+=t[i][j-1];
	for(int i=0;i<=b;i++)
		for(int j=1;j<=a;j++)
			t[j][i]+=t[j-1][i];
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			for(int k=0;k<a-i;k++){
				for(int l=0;l<b-j;l++){
					sum[i][j][k+1][l+1]=(t[k+i+1][l+j+1]-t[k][l+j+1]-t[k+i+1][l]+t[k][l]==0);
				}
			}
			for(int k=0;k<=a;k++)
				for(int l=1;l<=b;l++)
					sum[i][j][k][l]+=sum[i][j][k][l-1];
			for(int k=0;k<=b;k++)
				for(int l=1;l<=a;l++)
					sum[i][j][l][k]+=sum[i][j][l-1][k];
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a-i;j++){
			for(int k=0;k<b;k++){
				for(int l=k;l<b;l++){
					sum2[i][j+1][k][l]=sum2[i][j][k][l];
					for(int m=0;m<=l-k;m++){
						sum2[i][j+1][k][l]+=sum[i][m][j+1][l+1-m]-sum[i][m][j][l+1-m]-sum[i][m][j+1][k]+sum[i][m][j][k];
						
					}
				//	printf("%d %d %d %d: %d\n",i,j+1,k,l,sum2[i][j+1][k][l]);
				}
			}
		}
	}
	
	while(c--){
		int p,q,r,s;
		scanf("%d%d%d%d",&p,&q,&r,&s);
		int ret=0;
		for(int i=0;i<a;i++){
			if(r-p<i)break;
			ret+=sum2[i][r-i][q-1][s-1]-sum2[i][p-1][q-1][s-1];
		//	printf("%d: %d %d %d %d: %d %d %d %d:%d\n",i,i,r-i,r-1,s-1,sum2[i][r-i][r-1][s-1]-sum2[i][p-1][r-1][s-1]);
		}
		printf("%d\n",ret);
	}
}