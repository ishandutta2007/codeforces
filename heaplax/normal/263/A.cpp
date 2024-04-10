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

int main()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			int q;
			cin>>q;
			if(q==1)printf("%d\n",abs(i-3)+abs(j-3));
		}
	return 0;
}