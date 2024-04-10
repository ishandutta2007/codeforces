#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	int n;
	scanf("%d",&n);
	if(n<=2) return printf("1"), 0;
	int cur = 4;
	while(cur <= n)
	{
		if(n - cur <= 1) return printf("1"), 0;
		if(cur%2 == 0) cur = cur * 2 + 1;
		else cur = cur + (cur + 1) + 1;
	}
	printf("0");
	return 0;
}