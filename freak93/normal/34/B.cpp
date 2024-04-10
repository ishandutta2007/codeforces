#include<cstdio>
#include<algorithm>

using namespace std;

int i,n,m,a[5000],rez;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);

	sort(a+1,a+n+1);
	for(i=1;a[i]<0&&i<=n&&m;++i)
		rez-=a[i],--m;
	printf("%d",rez);
}