#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int sz = 1e6;

int main()
{
	int n, m;
	scanf("%d%d",&n,&m);
	ll a =n, b=m;
	int i;
	for(i=0;a<=b;++i)
	{
		a*=3;
		b*=2;
	}
	printf("%d\n",i);
}