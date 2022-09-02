#include <cstdio>
#include <algorithm>
using namespace std;
int x[101][101],y[101][101],maxi=0,a[101];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&x[i][j]);
		}
	}
	int g=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(j!=i){
			g=g | x[i][j];
			}
		}
		a[j]=g;
		g=0;
	}
	for(int i=1;i<=n;i++){
		if(i==1){
		printf("%d",a[i]);
		}else{
			printf(" %d",a[i]);
		}
	}
	printf("\n");
	scanf("%d",&g);
	return 0;
}