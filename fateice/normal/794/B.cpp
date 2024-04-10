#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	  printf("%.12lf ",sqrt(double(m)*m/n*i));
	return 0;
}