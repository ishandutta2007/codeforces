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
int n;
int main()
{
	scanf("%d",&n);
	if(n%2==0 && n>2)printf("YES\n");
	else printf("NO\n");
	return 0;
}