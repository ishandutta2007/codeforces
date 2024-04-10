#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define maxN 1
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define oo 1000111222
using namespace std;

vector <unsigned long long> a;

void gen(unsigned long long x)
{
	a.push_back(x);
	if (x<=oo)
	{
		gen(x*10+4); gen(x*10+7);
	}
}

unsigned long long calc(int n)
{
	unsigned long long re=0,last=0;
	if (!n) return 0;
	for (int i=0;i<int(a.size());i++)
		if (n<=a[i]) 
		{
			re+=a[i]*(n-last);
			return re;
		}
		else re+=a[i]*(a[i]-last), last=a[i];
	return re;
}

int main()
{
	int l,r;
	gen(4); gen(7);
	sort(a.begin(),a.end());
	cin >> l >> r;
	cout << calc(r)-calc(l-1) << endl;
}