#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t,a[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=30) printf("NO\n");
		else if(a[i]==36 || a[i]==40 || a[i]==44) printf("YES\n6 10 15 %d\n",a[i]-31);
		else printf("YES\n6 10 14 %d\n",a[i]-30);
	}
}