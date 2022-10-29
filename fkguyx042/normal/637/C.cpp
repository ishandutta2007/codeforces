#include<stdio.h>
#include<algorithm>
#define N 1005
using namespace std;
char a[N][8];int i,j,same,diff,ans,k,n;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	ans=7;
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++){
			same=diff=0;
			for (k=1;k<=6;k++)
				same+=a[i][k]==a[j][k],
				diff+=a[i][k]!=a[j][k];
			ans=min(ans,(diff+1)/2);
	  }
	printf("%d\n",ans-1);
}