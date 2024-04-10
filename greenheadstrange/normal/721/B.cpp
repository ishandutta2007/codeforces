#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 105
using namespace std;
int n,k;
int num[maxn];
char a[105][105]; 
char need[105];

int main()
{
	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)
	{	
		getchar();
		scanf("%s",a[i]);
		num[strlen(a[i])]++;
	}
	scanf("%s",need);
	int nlen=strlen(need);
	int mint=0,maxt=0;
	for(int i=1;i<nlen;i++) mint+=num[i];
	maxt=mint+num[nlen];
	mint++;
	int maxti,minti;
	maxti=((maxt-1)/k)*5+maxt;
	minti=((mint-1)/k)*5+mint;
	printf("%d %d\n",minti,maxti);
	return 0;
}