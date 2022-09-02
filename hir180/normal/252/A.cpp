#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int a,num[105];
	long long maxi=0,sum=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a-i;j++){
			sum=num[j];
			for(int k=j+1;k<=j+i;k++){
				sum^=num[k];
			}
			maxi=max(maxi,sum);
			sum=0;
		}
	}
	printf("%lld\n",maxi);
	return 0;
}