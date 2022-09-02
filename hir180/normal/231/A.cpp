#include <cstdio>
#include <algorithm>
using namespace std;
/*(^(^(^(^(^o^)^)^)^)^) ('') */
int main(){
	int n,i,a[1000],b[1000],c[1000],sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		if(a[i]==b[i] && a[i]==1){
			sum++;
			continue;
		}
		if(a[i]==c[i] && a[i]==1){
			sum++;
			continue;
		}
		if(c[i]==b[i] && b[i]==1){
			sum++;
			continue;
		}
	}
	printf("%d\n",sum);
	return 0;
}