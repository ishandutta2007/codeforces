#include <bits/stdc++.h>
using namespace std;

const long long o11 = 292LL;
int n, i, a, b, c, p;
set <int> Set;

int main ()
	{
	scanf ("%d",&n);
	if (n<=10)
		{
		Set.clear();
		for (a=0, b=0, c=0; a+b+c<=n; a++, b=0, c=0)
			for (b=0, c=0; a+b+c<=n; b++, c=0)
				for (c=0; a+b+c<=n; c++)
					Set.insert(a*50+b*10+c*5+(n-a-b-c));
		printf ("%d\n",(int)Set.size());
		}
	else
		printf("%lld\n",(o11+(((long long)(n)-11LL)*49LL)));
	return 0;
	}