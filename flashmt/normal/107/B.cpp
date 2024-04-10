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

int n,m,h,a[1111],s;
double re=1.0;

double P(int k,int n)
{
	double r=1;
	while (k<n) r*=++k;
	return r;
}

int main()
{
	int i;
	cin >> n >> m >> h;
	fr(i,1,m) cin >> a[i],s+=a[i];
	n--; a[h]--; s--;
	if (s<n) 
	{
		cout << "-1.000000" << endl; 
		return 0;
	}
	if (s-a[h]<n) 
	{
		cout << "1.000000" << endl;
		return 0;
	}
	re-=(P(s-a[h]-n,s-a[h])/P(s-n,s));
	printf("%.10lf\n",re);
	return 0;
}