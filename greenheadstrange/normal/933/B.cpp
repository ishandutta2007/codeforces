#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long 
using namespace std;
ll p;
int k;
int ns[maxn];
int main()
{
	scanf("%I64d%d", &p, &k);
	ll n1 = p, npl = 0;
	while(n1)
	{
		ll nmd = ((n1 % k) + k) % k;
		ns[npl] = nmd, n1 = (n1 - nmd) / k;
		npl++;
		n1 = -n1;
	}
	printf("%d\n", npl);
	for(int i = 0; i < npl; i++)
		printf("%d ", ns[i]);
		
	return 0;
 }