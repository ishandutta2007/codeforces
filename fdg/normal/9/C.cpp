#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

#define dat cin
#define sol cout

using namespace std;

int main()
{
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	long n,ans=0;
	dat >> n;
	for(int i=1;;i++)
	{
		long step=1,k=i,num=0;
		while(k>0)
		{
			num+=step*(k%2);
			k/=2;
			step*=10;
		}
		if (num<=n) ans++;
		else break;
	}
	sol << ans << endl;
	return 0;
}