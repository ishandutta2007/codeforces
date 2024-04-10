#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],i;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i]+=i;
	sort(a+1,a+1+n);
	for (i=1;i<=n;++i)
	   if(a[i-1]==a[i])
	 {
		puts(":(");
		return 0;
	 } 
	for (i=1;i<=n;++i)printf("%d ",a[i]-i);
}