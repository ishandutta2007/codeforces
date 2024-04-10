#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[110000],h[110000];
bool cmp(int n1,int n2) {return (a[n1]<a[n2]);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),h[i]=i;
		sort(h+1,h+n+1,cmp);
		
		printf("%d %d\n",h[1],h[n]);
	}
	
	
	return 0;
}