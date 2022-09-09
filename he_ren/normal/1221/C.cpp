#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(void)
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n", min((a+b+c)/3, min(a,b)));
	}
	return 0;
}