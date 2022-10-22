#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1010;
int a[N];

bool cmp(int n1,int n2 ) {return (n1<n2);}

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);
		printf("%d\n",a[n]+a[n-1]);
	}
	
	return 0;
}