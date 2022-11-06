#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,d,a[200010],b[200010],p,ans;
bool f[200010];
int main()
{
	scanf("%d%d",&n,&d);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	int l=1,r=n;
	a[d]+=b[1];
	f[d]=1;
	for (int i=1;i<=n;i++)
	 if (i!=d)
	 {
	 	if (a[i]+b[r]>a[d]) {a[i]+=b[l]; f[l]=1; while (f[l]) l++;}
	 	 else {a[i]+=b[r]; f[r]=1; while (f[r]) r--;}
	 }
	 for (int i=1;i<=n;i++) if (a[i]>a[d]) ans++;
	 //for (int i=1;i<=n;i++) printf("%d ",a[i]);
	 printf("%d\n",ans+1);
return 0;
}