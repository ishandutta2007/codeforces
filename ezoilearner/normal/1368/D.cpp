#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 200010
int bit[20];
int ans[Maxn],a[Maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=0;j<20;++j)
		    if(a[i]&(1<<j))bit[j]++;
	}
	for(int i=0;i<20;++i)
	    for(int j=n;j>n-bit[i];--j)ans[j]+=(1<<i);
	long long Ans=0;
	for(int i=1;i<=n;++i)Ans+=1ll*ans[i]*ans[i];
	printf("%lld\n",Ans);
	return 0;
}