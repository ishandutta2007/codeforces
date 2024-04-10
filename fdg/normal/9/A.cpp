#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

//#define dat cin
//#define sol cout

using namespace std;

int gcd(int a,int b) {return (b==0) ? a : gcd(b,a%b);}

int main()
{
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	long a,b,c,v=6,g;
	cin >> a >> b;
	c=6-max(a,b)+1;
	g=gcd(c,v);
	c/=g;
	v/=g;
	if (c==0)
	{
		cout << "0/1" << endl;
	}
	else
	{
		cout << c << "/" << v << endl;
	}
	return 0;
}