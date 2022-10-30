#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long i, j, x, ans, cur, n, k;
int main()
{
	cin>>n>>k;
	ans=0;
	for(i=0; i<k; i++)
	{
		ans=max(ans, ans+2*(n-2*i)-3);
	}
	cout<<ans;
}