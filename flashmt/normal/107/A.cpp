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

int n,Out[1111];
vector <int> re,a[1111],c[1111];
pii r[1111];

void visit(int x,int amount,int tap)
{
	if (a[x].empty())
	{
		re.pb(x);
		r[x]=mp(tap,amount);
		return;
	}
	int i;
	fr(i,0,int(a[x].size())-1) visit(a[x][i],min(amount,c[x][i]),tap);
}

int main()
{
	int i,p,x,y,z;
	cin >> n >> p;
	while (p--)
	{
		cin >> x >> y >> z;
		Out[x]=y; 
		a[y].pb(x);
		c[y].pb(z);
	}
	fr(i,1,n)
		if (!Out[i] && !a[i].empty()) visit(i,oo,i);
	if (!re.empty()) sort(re.begin(),re.end());
	cout << re.size() << endl;
	fr(i,0,int(re.size())-1) cout << re[i] << " " << r[re[i]].first << " " << r[re[i]].second << endl;
	return 0;
}