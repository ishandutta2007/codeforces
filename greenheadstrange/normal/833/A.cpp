#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		ll a, b;
		scanf("%I64d%I64d", &a, &b);
		ll l = 0, r = 1000005;
		while(l < r)
		{
			ll mid = (l + r) >> 1;
			if((mid + 1) * (mid + 1) * (mid + 1) <= a * b) l = mid + 1;
			else r = mid;
		} 
		if(l * l * l == a * b && (!(a % l)) && (!(b % l))) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
 }