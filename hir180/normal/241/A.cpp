#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int a[1001],b[1001],n,k,sum=0;
	int c[1001]={},d[1001]={},e[1001];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i!=0){
			c[i]=c[i-1]+a[i];
		}else{
			c[i]=a[i];
		}
	}
	sum=c[n-1];
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		if(i!=0){
			d[i]=d[i-1]+b[i];
			e[i]=max(e[i-1],b[i]);
		}else{
			d[i]=b[i];
			e[i]=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(c[i]>d[i]){
                    while(c[i]>d[i]){
			sum+=k;
			for(int j=i;j<n;j++){
				d[j]+=e[i];
			}
                    }
		}
	}
	printf("%d\n",sum);
	scanf("%d",&n);
	return 0;
}