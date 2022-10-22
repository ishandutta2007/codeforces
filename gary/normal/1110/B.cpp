#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k,a[100001],sum[100001];
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(i!=1){
			sum[i]=a[i]-a[i-1]-1;
		}
	}
	int Sum=a[n]-a[1]+1;
	sort(sum+2,sum+1+n);
	int j=n;
	for(int i=1;i<k;i++){
		Sum-=sum[j];
		j--;
	}
	printf("%d\n",Sum);
	return 0;
}