#include<cstdio>
using namespace std;
int main(){
	long long t,n;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		long long ans=0;
		for(long long i=1;i<=9;++i){
			long long tmp=i;
			while(tmp<=n){
				++ans;
				tmp=tmp*10+i;
			}
		}
		printf("%lld\n",ans);
	}
}