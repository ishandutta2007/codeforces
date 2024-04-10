#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
#define Maxn 100010
int a[Maxn];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		long long Ans=0,tmp=0;
		for(int i=2;i<=n;++i){
			ll p=a[i-1]-a[i];
			tmp=max(0ll,tmp+p);
			Ans=max(Ans,tmp);
		}
		if(!Ans){
			puts("0");
			continue;
		}
		int res=0;
		ll ans=1;
		while(ans<=Ans){
			res++;
			ans*=2;
		} 
		printf("%d\n",res);
	}
	return 0;
}