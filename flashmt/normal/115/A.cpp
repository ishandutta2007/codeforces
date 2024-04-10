#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int n,d[2020];
vector <int> a[2020];

int visit(int x)
{
	int i,r=0;
	d[x]=1;
	fr(i,0,int(a[x].size())-1)
		r=max(r,visit(a[x][i]));
	return r+1;
}

int main()
{
	int i,x;
	cin >> n;
	fr(i,1,n)
	{
		cin >> x;
		if (x>=0) a[x].push_back(i);
	}
	int re=1;
	fr(i,1,n)
		if (!d[i]) re=max(re,visit(i));
	cout << re << endl;
	return 0;
}