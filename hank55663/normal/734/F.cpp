#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int a[200005],b[200005],c[200005];
int main(){
	long long int n;
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)
	scanf("%I64d",&b[i]);
	for(int i=0;i<n;i++)
	scanf("%I64d",&c[i]);
	ll sum=0;
	for(int i=0;i<n;i++)
	sum+=b[i]+c[i];
	if(sum%(2*n)!=0){
		printf("-1\n");
		return 0;
	}
	sum/=2*n;
	for(int i=0;i<n;i++)
	a[i]=b[i]+c[i];
	for(int i=0;i<n;i++){
		a[i]-=sum;
		if(a[i]%n!=0)
		{
			printf("-1\n");
			return 0;
		}
		a[i]/=n;
	}
	int bit[100];
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++){
		int d=a[i];
		for(int j=0;d!=0;j++){ 
			bit[j]+=d&1;
			d>>=1;
		} 
	}
	for(int i=0;i<n;i++){
		int d=a[i];
		sum=0;
		for(int j=0;d!=0;j++){
			if(d&1)
			sum+=bit[j]<<j;
			d/=2;
		}
		if(sum!=b[i]){
			printf("-1\n");
			return 0;
		}
		d=a[i];
		sum=0;
		for(int j=0;j<32;j++){
			if(d&1)
			sum+=n<<j;
			else
			sum+=bit[j]<<j;
			d/=2;
		}
		if(sum!=c[i]){
		//	printf("%d %d\n",sum,c[i]);
			printf("-1\n");
			return 0;
		}
	}
	printf("%I64d",a[0]);
	for(int i=1;i<n;i++)
	printf(" %I64d",a[i]);
	printf("\n");
}