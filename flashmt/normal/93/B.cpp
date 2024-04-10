#include <iostream>
#include <cstdio>
using namespace std;
      
int main()
{
	int m,n,w;
	cin >> n >> w >> m;
	double per=1.0*n*w/m;
	if (m>n*2) 
	{
		puts("NO");	return 0;
	}
	
	if (m<=n) 
	{
		puts("YES");
		int bottle=1;
		double rest=1.0*w;
		for (int cup=1;cup<=m;cup++)
		{
			double need=per;
			while (need>0)
			{
				double amount=min(rest,need);
				if (bottle>n) break;
				printf("%d %.9lf ",bottle,amount);
				need-=amount; rest-=amount;
				if (rest==0.0) bottle++, rest=1.0*w;
			}
			puts("");
		}
		return 0;
	}
	
	if (n%(m-n)==0)
	{
		double rest=1.0*w-per;
		int group=n/(m-n);
		puts("YES");
		for (int cup=1;cup<=n;cup++) printf("%d %.9lf\n",cup,per);
		for (int cup=1;cup<=m-n;cup++)
		{
			for (int i=(cup-1)*group+1;i<=cup*group;i++)
					printf("%d %.9lf ",i,rest);
			puts("");
		}
	}
	else puts("NO");
	
	return 0;
}