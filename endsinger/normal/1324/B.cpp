#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int t,a[N],n,l[N],r[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			l[i]=r[i]=-1;
		}
		for(int i=1;i<=n;i++)
			r[a[i]]=i;
		for(int i=n;i>=1;i--)
			l[a[i]]=i;
		int fl=0;
		for(int i=1;i<=n;i++)
			if(r[i]-l[i]>1)
				fl=1;
		puts(fl?"YES":"NO");
	}
	return 0;
}