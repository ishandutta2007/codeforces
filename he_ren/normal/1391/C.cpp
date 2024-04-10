#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;

int main(void)
{
	int n;
	scanf("%d",&n);
	
	ll facn = 1;
	for(int i=1; i<=n; ++i)
		facn = facn * i %mod;
	
	ll fob = 1;
	for(int i=1; i<=n-1; ++i)
		fob = fob * 2 %mod;
	
	printf("%lld",(facn - fob + mod) %mod); 
	return 0;
}