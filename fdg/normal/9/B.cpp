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

int gcd(int a,int b) {return (b==0) ? a : gcd(b,a%b);}

int main()
{
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	double n,vb,vs,x,y;
	dat >> n >> vb >> vs;
	vector <double> ost(n,0);
	for(int i=0;i<n;i++)
		dat >> ost[i];
	dat >> x >> y;
	double mint,num=-1;
	for(int i=n-1;i>=1;i--)
	{
		if (num==-1||mint>ost[i]/vb+(sqrt((x-ost[i])*(x-ost[i])+(y)*(y)))/vs)
		{
			mint=ost[i]/vb+(sqrt((x-ost[i])*(x-ost[i])+(y)*(y)))/vs;
			num=i+1;
		}
	}
	sol << num << endl;
	return 0;
}