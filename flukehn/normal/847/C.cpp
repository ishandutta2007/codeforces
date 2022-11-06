#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int main()
{
	int n;long long k;
	cin>>n>>k;
	long long maxx=1LL*n*(n-1)/2;
	if(maxx<k)
	{
		printf("Impossible");
		return 0;
	}
	int sum=0;
	for(int i=n-1;i;i--)
	{
		if(k>=i)
		{
			k-=i;
			sum++;
		}
		else break;
	}
	//cout<<sum;
	for(int i=1;i<=sum;i++)
	printf("(");
	n-=sum;
	printf("(");
	for(int i=1;i<=k;i++)
	{
		printf("()");
	}printf(")");
	for(int i=1;i<=n-k-1;i++)
	printf("()");
	
	for(int i=1;i<=sum;i++)
	printf(")");
}