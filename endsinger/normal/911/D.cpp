#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int a[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j])
				k^=1;
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int len=r-l+1;
		if(len*(len-1)/2%2)
			k^=1;
		puts(k?"odd":"even");
	}
	return 0;
}