#include<cstdio>

using namespace std;

int rez,a[500],x,y,n,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
		scanf("%d",&a[i]);
	scanf("%d%d",&x,&y);
	while(x<y)
		rez+=a[x++];
	printf("%d",rez);
}