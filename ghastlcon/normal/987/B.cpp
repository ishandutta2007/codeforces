#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

const long double eps=1e-15;

int main()
{
	
	
	int x,y;
	scanf("%d%d",&x,&y);
	long double lx=log( (long double)x );
	long double ly=log( (long double)y );
	lx=lx*(long double)y;
	ly=ly*(long double)x;
	if ( lx<ly-eps ) printf("<\n");
	else
		if ( lx-eps>ly ) printf(">\n");
		else printf("=\n");
	
	return 0;
}