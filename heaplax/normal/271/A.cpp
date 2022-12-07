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
int y;
bool ok(int n)
{
	int a,b,c,d;
	int have[10];
	memset(have,0,sizeof(have));
	a=n/1000,b=(n/100)%10,c=(n/10)%10,d=n%10;
	have[a]++,have[b]++,have[c]++,have[d]++;
	for(int i=0;i<=9;i++)if(have[i]>1)return false;
	return true;
}
int main()
{
	scanf("%d",&y);
	y++;
	while(!ok(y))y++;
	printf("%d\n",y);
	return 0; 
}