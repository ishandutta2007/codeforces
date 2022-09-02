#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m,num=0,ans=0,sum=0;
/*('')*/
int main(){
	scanf("%d",&n);
	if(n<=2){
		printf("-1\n");
	}else{
		for(int i=n;i>=1;i--){
			if(i==n){
				printf("%d",i);
			}else{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	scanf("%d",&n);
	return 0;
}