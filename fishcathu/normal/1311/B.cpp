#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x;
	scanf("%d",&x);
	for(int m,n;x--;)
	{
		scanf("%d%d",&m,&n);
		int a[m+1],b[n];
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		sort(b,b+n);
		int i=1;
		for(int a1=0,a2,a3=0,a4=101,j=0;i<=m;i++)
		{
			if(a[i]>a3)a3=a[i];
			if(a[i]<a4)a4=a[i];
			if(i==b[j])j++;
			else 
			{
				if(a1>a4)break;
				else a1=a3,a2=a4,a3=0,a4=101;
			}
		}
		printf(i>m?"YES\n":"NO\n");
	}
	return 0;
}