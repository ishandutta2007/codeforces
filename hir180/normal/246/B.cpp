#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m,num=0,ans=0,sum=0;
int x[1000000];
/*('')*/
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	if(sum%n==0){
		printf("%d\n",n);
	}else{
		printf("%d\n",n-1);
	}
	return 0;
}