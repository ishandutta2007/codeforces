#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],b[N];

bool cmp(int n1,int n2) {return (n1>n2);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K;scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) b[i]=a[i]-(n-i);
		sort(b+1,b+n+1,cmp);
		ll Ans=0,Sum=0;
		for(int i=1;i<=n;i++) Sum=Sum+a[i];
		Ans=Sum;
		for(int i=1;i<=K;i++){
			Sum=Sum-b[i];
			ll t=Sum-(ll)i*(i-1)/2;
			if(Ans>t) Ans=t;
		}
		
		printf("%lld\n",Ans);
	}
	
	return 0;
}