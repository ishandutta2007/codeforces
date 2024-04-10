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

int a,b,c;

int gcd(int a,int b)
{
	if (!a || !b) return a+b;
	return gcd(b,a%b);
}

int main()
{
	cin >> a >> b;
	c=gcd(a,b);
	a/=c;
	b/=c;
	if (a>b) --a;
	else --b;
	if (a==b) cout << "Equal" << endl;
	else
		if (a<b) cout << "Dasha" << endl;
		else cout << "Masha" << endl;
	return 0;
}