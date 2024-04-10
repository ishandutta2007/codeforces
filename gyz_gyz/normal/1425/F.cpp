#include<bits/stdc++.h>
using namespace std;
#define N 1010
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=2;i--){
		printf("? %d %d\n",1,i);
		fflush(stdout);
		scanf("%d",&a[i]);
		a[i+1]-=a[i];
	}
	printf("? %d %d\n",2,3);
	fflush(stdout);
	scanf("%d",&a[0]);
	a[1]=a[2]-(a[0]-a[3]);
	a[2]=a[0]-a[3];
	printf("!");
	for(int i=1;i<=n;i++)
	  printf(" %d",a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}