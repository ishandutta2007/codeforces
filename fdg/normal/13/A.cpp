#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define dat cin
#define sol cout
#define ll long long

using namespace std;

ll gcd(ll a,ll b) {return (b==0) ? a : gcd(b,a%b);}

int main()
{
//	ifstream dat("input.txt");
//	ofstream sol("output.txt");
	ll a,sum=0;
	dat >> a;
	for(int i=2;i<a;i++)
	{
		ll k=a;
		while(k>0)
		{
			sum+=k%i;
			k/=i;
		}
	}
	sol << sum/gcd(a-2,sum) << "/" << (a-2)/gcd(a-2,sum) << endl;
	return 0;
}