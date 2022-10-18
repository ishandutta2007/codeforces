#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,w,m;
	cin >> n >> w >> m;
	double one=1.0*n*w/m;
/*	if (2.0*w/3>one)
	{
		cout << "NO\n";
		return 0;
	}
	printf("YES\n");
*/	bool ok=true;
	int cur=1,cnt=0;
	double left=w;
	double in[100]={0};
	for(int i=0;i<m;i++)
	{
		while(in[i]+1e-6<one)
		{
			double val=min(one-in[i],left);
			left-=val;
			in[i]+=val; cnt++;
			if (cnt>2) ok=false;
			if (left<1e-6)
			{
				left=w; cur++; cnt=0;
			}
		}
	}
	if (!ok) printf("NO\n");
	else
	{
		printf("YES\n");
		cur=1,cnt=0;
		left=w;
		for(int i=0;i<m;i++) in[i]=0;
		for(int i=0;i<m;i++)
		{
			bool f=true;
			while(in[i]+1e-6<one)
			{
				if (!f) printf(" "); f=false;
				double val=min(one-in[i],left);
				printf("%d %.7lf",cur,val);
				left-=val;
				in[i]+=val; cnt++;
				if (cnt>2) ok=false;
				if (left<1e-6)
				{
					left=w; cur++; cnt=0;
				}
			}
			printf("\n");
		}
	}
	return 0;
}