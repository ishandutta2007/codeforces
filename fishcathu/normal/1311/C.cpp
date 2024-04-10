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
		string a;
		int b[n],c[26]={0};
		cin>>a;
		int d[m+1];
		for(int i=1;i<=m;i++)d[i]=a[i-1]-97;
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		sort(b,b+n);
		for(int i=m+1,j=n-1,k=1;--i;)
		{
			while(j>=0&&i==b[j])j--,k++;
			c[d[i]]+=k;
		}
		for(int i=0;i<26;i++)printf("%d ",c[i]);
		putchar('\n');
	}
	return 0;
}