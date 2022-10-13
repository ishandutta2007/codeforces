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

int N,g[100100],d[22],re[100100];

void Init()
{
	int i,n,l,r,j;
	fr(n,3,N)
	{
		re[n]=n+1;
		fr(i,0,20) d[i]=0;
		fr(i,2,n)
			if (i*i>n*2) break;
			else
				if (n*2%i==0)
				{
					j=n*2/i;
					if (j%2==i%2) continue;
					r=(j+i-1)/2;
					l=j-r;
					d[g[r]^g[l-1]]=1;
					if (g[r]==g[l-1]) re[n]=min(re[n],i);
				}
		fr(i,0,20) 
			if (!d[i]) break;
		g[n]=g[n-1]^i;
	}
}

int main()
{
	cin >> N;
	Init();
	if (N<3 || re[N]>N) cout << -1 << endl;
	else cout << re[N] << endl;
  return 0;
}