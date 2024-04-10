#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[2005],i,maxt,rez,k;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	maxt=-1;
	k=1;
	for(i=2;i<=n;++i)
		if(a[i]!=a[i-1])
			maxt=max(maxt,k),k=1,++rez;
		else
			++k;
	maxt=max(maxt,k),++rez;
	printf("%d %d\n",maxt,rez);
}