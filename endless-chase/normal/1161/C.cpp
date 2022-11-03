#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,num[111];
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]++;
	}
	f=0;
	for (int i=1;i<=50;i++)
	{
		if (num[i])
		{
			if (num[i]>n/2) f=1;
			break;
		}
	}
	if (f) printf("Bob\n");
	else printf("Alice\n");
	return Accepted;
}