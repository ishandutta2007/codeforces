#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N];bool bk[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) bk[i]=false;
		
		int Sum=0;
		for(int i=n;i>=1;i--){
			if(Sum<a[i]&&Sum<q) bk[i]=true,Sum++;
			else if(Sum>=a[i]) bk[i]=true;
		}
		
		for(int i=1;i<=n;i++) printf("%d",bk[i]);
		printf("\n");
	}
	
	return 0;
}