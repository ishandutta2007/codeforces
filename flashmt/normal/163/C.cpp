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
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,l,v1,v2;
map <double,int> d;
double f[100100];

int main()
{
	cin >> n >> l >> v1 >> v2;
	double D=1.0*v2*l/(v1+v2);
	int x;
	d[l*2]=0;
	rep(i,n) 
	{
		cin >> x;
		double y=D+x;
		d[x]++;
		if (y<=l*2) d[y]--;
		else d[l*2]--, d[0]++, d[y-l*2]--;
	}
	
	int cur=0;
	double last=0;
	for (map<double,int>::iterator it=d.begin();it!=d.end();it++)
	{
		f[cur]+=it->fi-last;
		cur+=it->se;
		last=it->fi;
	}
	
	rep(i,n+1) printf("%.12lf\n",f[i]/l/2);
}