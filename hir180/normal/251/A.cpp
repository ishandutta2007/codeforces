#include <cstdio>
#include <algorithm>
using namespace std;
int n,d;
int num[100005];
long long sum=0;
int main(){
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n-2;i++){
		long long ss=upper_bound(num,num+n,num[i]+d)-num;
		ss--;
		if(ss-i>=2){
			sum+=(ss-i)*(ss-i-1)/2;
		}
	}
	printf("%lld\n",sum);
	return 0;
}