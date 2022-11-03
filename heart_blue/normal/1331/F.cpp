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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
map<string, int> ms;
void init()
{
	ms["H"] = 1;
	ms["HE"] = 1;
	ms["LI"] = 1;
	ms["BE"] = 1;
	ms["B"] = 1;
	ms["C"] = 1;
	ms["N"] = 1;
	ms["O"] = 1;
	ms["F"] = 1;
	ms["NE"] = 1;
	ms["NA"] = 1;
	ms["MG"] = 1;
	ms["AL"] = 1;
	ms["SI"] = 1;
	ms["P"] = 1;
	ms["S"] = 1;
	ms["CL"] = 1;
	ms["AR"] = 1;
	ms["K"] = 1;
	ms["CA"] = 1;
	ms["SC"] = 1;
	ms["TI"] = 1;
	ms["V"] = 1;
	ms["CR"] = 1;
	ms["MN"] = 1;
	ms["FE"] = 1;
	ms["CO"] = 1;
	ms["NI"] = 1;
	ms["CU"] = 1;
	ms["ZN"] = 1;
	ms["GA"] = 1;
	ms["GE"] = 1;
	ms["AS"] = 1;
	ms["SE"] = 1;
	ms["BR"] = 1;
	ms["KR"] = 1;
	ms["RB"] = 1;
	ms["SR"] = 1;
	ms["Y"] = 1;
	ms["ZR"] = 1;
	ms["NB"] = 1;
	ms["MO"] = 1;
	ms["TC"] = 1;
	ms["RU"] = 1;
	ms["RH"] = 1;
	ms["PD"] = 1;
	ms["AG"] = 1;
	ms["CD"] = 1;
	ms["IN"] = 1;
	ms["SN"] = 1;
	ms["SB"] = 1;
	ms["TE"] = 1;
	ms["I"] = 1;
	ms["XE"] = 1;
	ms["CS"] = 1;
	ms["BA"] = 1;
	ms["LA"] = 1;
	ms["CE"] = 1;
	ms["PR"] = 1;
	ms["ND"] = 1;
	ms["PM"] = 1;
	ms["SM"] = 1;
	ms["EU"] = 1;
	ms["GD"] = 1;
	ms["TB"] = 1;
	ms["DY"] = 1;
	ms["HO"] = 1;
	ms["ER"] = 1;
	ms["TM"] = 1;
	ms["YB"] = 1;
	ms["LU"] = 1;
	ms["HF"] = 1;
	ms["TA"] = 1;
	ms["W"] = 1;
	ms["RE"] = 1;
	ms["OS"] = 1;
	ms["IR"] = 1;
	ms["PT"] = 1;
	ms["AU"] = 1;
	ms["HG"] = 1;
	ms["TL"] = 1;
	ms["PB"] = 1;
	ms["BI"] = 1;
	ms["PO"] = 1;
	ms["AT"] = 1;
	ms["RN"] = 1;
	ms["FR"] = 1;
	ms["RA"] = 1;
	ms["AC"] = 1;
	ms["TH"] = 1;
	ms["PA"] = 1;
	ms["U"] = 1;
	ms["NP"] = 1;
	ms["PU"] = 1;
	ms["AM"] = 1;
	ms["CM"] = 1;
	ms["BK"] = 1;
	ms["CF"] = 1;
	ms["ES"] = 1;
	ms["FM"] = 1;
	ms["MD"] = 1;
	ms["NO"] = 1;
	ms["LR"] = 1;
	ms["RF"] = 1;
	ms["DB"] = 1;
	ms["SG"] = 1;
	ms["BH"] = 1;
	ms["HS"] = 1;
	ms["MT"] = 1;
	ms["DS"] = 1;
	ms["RG"] = 1;
	ms["CN"] = 1;
	ms["NH"] = 1;
	ms["FL"] = 1;
	ms["MC"] = 1;
	ms["LV"] = 1;
	ms["TS"] = 1;
	ms["OG"] = 1;
}
char str[100];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	dp[0] = 1;
	string str;
	cin >> str;
	int n = str.length();
	str = "1" + str;
	for (int i = 1; i <= n; i++)
	{
		for (int o = 0; o <= 1 && i + o <= n; o++)
		{
			if (ms.count(str.substr(i, o + 1)))
				dp[i + o] |= dp[i - 1];
		}
	}
	if (dp[n]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}