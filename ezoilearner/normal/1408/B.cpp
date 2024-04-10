#include<bits/stdc++.h>
using namespace std;
int n,K;
#define Maxn 105
int a[Maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>K;
		int cnt=0;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=n;i>=2;--i){
			a[i]-=a[i-1];
			if(a[i]>0)cnt++;
		}
		K--;
		if(cnt==0){
			puts("1");
			continue;
		}
		if(K==0){
			puts("-1");
			continue;
		}
		printf("%d\n",(cnt+K-1)/K);
	}
	return 0;
}