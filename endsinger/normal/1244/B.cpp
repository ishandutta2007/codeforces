#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",a+1);
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='1')
			{
				mx=max(mx,i);
				mx=max(mx,n-i+1);	
			}	
		} 
		printf("%d\n",(mx==0?n:mx*2));
	} 
	return 0;
}