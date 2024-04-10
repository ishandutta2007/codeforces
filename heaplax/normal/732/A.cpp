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
int k,r;
int main()
{
	scanf("%d%d",&k,&r);
	for(int i=1;i<=10;i++)
		if(k*i%10==0 ||(k*i-r)%10==0)
		{
			printf("%d\n",i);
			return 0;
		}
}