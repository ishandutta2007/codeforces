#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	string ar[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int n;
	string s;
	cin >> n >>  s;
	int res = -1;
	for(int i=0;i<8;i++)
	{
		bool ok = true;
		if(ar[i].size() != s.size()) ok = false;
		else
		{
			for(int j=0;j<s.size();j++)
			{
				if(s[j] != '.' && s[j] != ar[i][j]) ok = false;
			}
		}
		if(ok) res = i;
	}
	cout << ar[res] << endl;
}