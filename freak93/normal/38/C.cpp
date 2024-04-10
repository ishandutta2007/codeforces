#include<cstdio>
#include<algorithm>

using namespace std;

int a[500],j,n,l,i,aux,rez;

int main()
{
	scanf("%d%d",&n,&l);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=100;i>=l;--i)
	{
		aux=0;
		for(j=1;j<=n;++j)
			aux+=a[j]-a[j]%i;
		rez=max(rez,aux);
	}
	printf("%d",rez);
}