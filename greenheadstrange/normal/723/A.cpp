#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 105
using namespace std; 
int x[3]; 
int main()
{
	for(int i=0;i<3;i++) scanf("%d",&x[i]);
	sort(x,x+3);
	printf("%d\n",x[2]-x[0]);
	return 0;
}