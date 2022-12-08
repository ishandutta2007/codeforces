#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int main()
{
	bool ar[100000];
	int n, m, z;
	scanf("%d%d%d",&n,&m,&z);
	rep(i,0,z+1)
		ar[i] = false;
	for(int i=n;i<=z;i+=n)
		ar[i] = true;
	int count = 0;
	for(int i=m;i<=z;i+=m)
		if(ar[i])
		{
			//debug(i);
			count++;
		}
	printf("%d\n",count);
}