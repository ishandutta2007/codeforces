#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N];

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		
		if(n%2==1){
			printf("NO\n");
			continue;
		}
		
		bool pd=true;
		for(int i=n/2+1;i<n;i++)
			if(a[i]==a[i-n/2+1])
				{pd=false;break;}
				
		if(!pd){
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		for(int i=1;i<=n/2;i++) printf("%d %d ",a[i],a[i+n/2]);
		printf("\n");
	}
	
	return 0;
}