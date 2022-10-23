#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

int a[MAXN], bak[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), ++bak[a[i]];
	
	for(int i=1; i<d; ++i)
	{
		if(bak[i] % (i+1))
		{
			printf("No\n");
			return 0;
		}
		bak[i+1] += bak[i] / (i+1);
	}
	
	printf("Yes\n");
	return 0;
}