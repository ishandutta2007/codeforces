#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int x;
	scanf("%d",&x);
	double X=labs(x),D=1+8*X,x1=(-1+sqrt(D))/2;
	long long ans=0,X1=x1;
	x=labs(x);
	if (X1*(X1+1)/2<x)
	{
		X1++;
	}
	if ((X1*(X1+1)/2)%2==x%2) ans=X1;
	else 
	{
		X1++;
		if ((X1*(X1+1)/2)%2==x%2) ans=X1;
		else
		{
			X1++;
			if ((X1*(X1+1)/2)%2==x%2) ans=X1;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}