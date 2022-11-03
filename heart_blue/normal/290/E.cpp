#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int fq = str.find("Q");
	if (fq == string::npos)
	{
		cout << "Yes" << endl;
		return 0;
	}
	fq /= 2;
	int noq = count(str.begin(), str.end(), 'Q');
	int nq = sqrt(noq);
	int nh = (str.size() - noq) / (nq + 1);
	string a = str.substr(fq, nh + nq);
	string t;
	for (int i = 0; i < int(a.size()); i++)
	{
		if (a[i] == 'H')
			t += "H";
		else
			t += a;
	}
	cout << (str == t ? "Yes" : "No");
	return 0;
}