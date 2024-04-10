#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

LL sum(LL x){
	if(!x) return 0;
	return x%10+sum(x/10);
}

int main(){
#ifdef DEBUG
	//freopen("A.in","r",stdin);
#endif
	LL n;
	scanf("%lld",&n);
	int cnt=0;
	for(int i=1;i<=10000 && i<=n;i++)
		if(sum(n-i)==i)
			cnt++;
	printf("%d\n",cnt);
	for(int i=min(n,10000LL);i>=1;i--)
		if(sum(n-i)==i)
			printf("%d ",n-i);
	return 0;
}