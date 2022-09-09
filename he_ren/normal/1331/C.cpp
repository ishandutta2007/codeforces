/*
And after happily lived ever they
5    4      3      2	 1	  0
And they lived happily ever after
5    0     2    3       1     4
8
*/

#include<cstdio>
#include<algorithm>
using namespace std;

int t[10] = {5,0,2,3,1,4};

int p[10],q[10];

int main(void)
{
	int a;
	scanf("%d",&a);
	for(int i=0; i<6; ++i)
		p[i]=a&1, a>>=1;
	for(int i=0; i<6; ++i)
		q[i] = p[t[i]];
	
	int b=0;
	for(int i=0; i<6; ++i)
		b<<=1, b|=q[i];
	printf("%d",b);
	return 0;
}