#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>

using namespace std;

typedef long double ld;


bool solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> v(n);
	int inc = 0, dec = 99999999;
	int vt=0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	//	assert(v[i]<=1e6);
		int d1 = min(v[i], dec), d2 = inc;
		d2 = max(d2, v[i] - d1);
		if (d2 > v[i])
			vt=1;
		inc = d2;
		dec = v[i] - d2;
	//	assert(inc>=0);
	//	assert(dec>=0);
	}
	if(vt)
		return false;
	return true;
}

int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	int n;
	cin >> n;
}