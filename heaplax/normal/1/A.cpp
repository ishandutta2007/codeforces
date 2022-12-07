#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
long long n,m,a,l,w;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	l=n/a;
	w=m/a;
	if(n%a!=0)l++;
	if(m%a!=0)w++;
	printf("%I64d\n",l*w);
	return 0;
}