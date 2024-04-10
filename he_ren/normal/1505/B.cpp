#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	int x;
	scanf("%d",&x);
	
	int res = 0;
	while(x) res += x % 10, x /= 10;
	res %= 9;
	
	printf("%d",res? res: 9);
	return 0;
}