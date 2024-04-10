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

int n,k,A,b[8],l[8];
double re=0.0;

void work()
{
	int i,s;
	double r=0.0;
	fr(s,0,(1<<n)-1)
	{
		int cnt=0,B=0;
		double p=1;
		fr(i,0,n-1)
			if ((s>>i)&1) cnt++, p*=0.1*l[i];
			else B+=b[i], p*=(1.0-0.1*l[i]);
		if (cnt*2>n) r+=p;
		else r+=p*A/(A+B);
	}
	re=max(re,r);
}

void att(int x,int last)
{
	work();
	if (x>k) return;
	int i;
	fr(i,last,n-1)
		if (l[i]<10)
		{
			l[i]++;
			att(x+1,i);
			l[i]--;
		}
}

int main()
{
	//freopen("b.in.2","r",stdin);
	int i;
	cin >> n >> k >> A;
	fr(i,0,n-1) cin >> b[i] >> l[i], l[i]/=10;
	att(1,0);
	printf("%.10lf\n",re);
	return 0;
}