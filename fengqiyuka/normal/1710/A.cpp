#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+100;
int a[N],b[N];

bool cmp(int n1,int n2) {return (n1>n2);}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m,K;bool pd=false;
		scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=K;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<=K;i++) b[i]=a[i]/n;
		sort(b+1,b+K+1,cmp);
		
		ll Min=0,Max=0;
		for(int i=1;i<=K;i++){
			if(b[i]>=2) Min+=2,Max+=b[i];
			if(Min<=m&&m<=Max) pd=true;
		}
		
		for(int i=1;i<=K;i++) b[i]=a[i]/m;
		sort(b+1,b+K+1,cmp);
		
		Min=Max=0;
		for(int i=1;i<=K;i++){
			if(b[i]>=2) Min+=2,Max+=b[i];
			if(Min<=n&&n<=Max) pd=true;
		}
		
		if(pd) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}