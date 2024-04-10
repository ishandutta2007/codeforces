#include<bits/stdc++.h>
using namespace std;
long long ans,a[100005];
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long mx=-1e9;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1,[](long long x,long long y){return abs(x)>abs(y);});
		if(mx<0){
		    cout<<a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]<<'\n';
		    continue;
		}
		ans=a[1]*a[2]*a[3]*a[4]*a[5];
		for(int i=6;i<=n;i++){
		    for(int j=1;j<=5;j++){
		        long long tmp=a[i];
		        for(int k=1;k<=5;k++){
		            if(k!=j)tmp*=a[k];
		        }
		        ans=max(ans,tmp);
		    }
		}
		printf("%lld\n",ans);
	}
    return 0;
}