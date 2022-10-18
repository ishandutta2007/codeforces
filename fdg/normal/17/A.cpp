#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <memory.h>

#define dat cin
#define sol cout

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	int n,k;
	dat >> n >> k;
	bool prime[1003]={0};
	prime[2]=true;
	vector <long> Nums(1,2);
	for(int i=3;i<=n;i++)
	{
		bool pr=true;
		for(int j=2;j*j<=i;j++)
			if (i%j==0)
			{
				pr=false;
				break;
			}
		prime[i]=pr;
		if (pr) Nums.push_back(i);
	}
	int num=0;
	for(int i=2;i<=n;i++)
	{
		if (!prime[i]) continue;
		bool fdg=false;
		for(int j=0;j<Nums.size()-1;j++)
			if (Nums[j]+Nums[j+1]==i-1)
			{
				fdg=true;
				break;
			}
			num+=fdg;
	}
	if (num>=k) sol << "YES\n";
	else sol << "NO\n";
	return 0;
}