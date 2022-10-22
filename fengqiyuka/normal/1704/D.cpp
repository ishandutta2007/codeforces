#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+100;
vector<ll> a[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++) a[i].resize(m+1);
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%lld",&a[i][j]);
				
		for(int i=1;i<n;i++){
			ll Sum=0;
			for(int j=1;j<=m;j++) Sum=Sum+(a[i][j]-a[i+1][j])*j;
			if(Sum!=0){
				if(Sum>0) printf("%d %lld\n",i,Sum);
				else printf("%d %lld\n",i+1,-Sum);
				break;
			}
		}
				
		for(int i=0;i<=n;i++) a[i].clear();
	}
	
	return 0;
}