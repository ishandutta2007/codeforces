#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N];ll qz[N];

int main()
{
	int T;scanf("%d",&T);
	
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		if(K<=n){
			qz[0]=0;
			for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
			
			ll Max=0;
			for(int i=K;i<=n;i++){
				if(Max<qz[i]-qz[i-K]) Max=qz[i]-qz[i-K];
			}
			printf("%lld\n",Max+(ll)K*(K-1)/2);
		}
		else{
			ll Sum=0;
			for(int i=1;i<=n;i++) Sum+=a[i];
			Sum=Sum+(ll)n*K-(ll)n*(n+1)/2;
			printf("%lld\n",Sum);
		}
	}
	
	return 0;
}