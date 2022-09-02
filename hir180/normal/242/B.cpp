#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
	long long x[1000000],y[1000000],a[1000000],b[1000000];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&x[i],&y[i]);
		a[i]=x[i];
		b[i]=y[i];
	}
	sort(x,x+n);
	sort(y,y+n);
	for(int i=0;i<n;i++){
		if(a[i]==x[0] && b[i]==y[n-1]){
			printf("%d\n",1+i);
			goto e;
		}
	}
	printf("-1\n");
	e:;
	return 0;
}