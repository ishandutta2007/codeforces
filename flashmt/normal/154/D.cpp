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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int main()
{
	long long x1,x2,a,b;
	cin >> x1 >> x2 >> a >> b;
	long long n=x2-x1;
	if (a>0)
	{
		if (n<0)
		{
			puts("DRAW");
			return 0;
		}
		
		long long N=n%(a+b);
		if (!N) puts("SECOND");
		else
			if (N>=a && N<=b)
			{
				puts("FIRST");
				cout << x1+N << endl;
			}
			else puts("DRAW");
	}
	else
		if (b<0)
		{
			if (n>0) 
			{
				puts("DRAW");
				return 0;
			}
			
			n=-n; a=-a; b=-b;
			swap(a,b);
			long long N=n%(a+b);
			if (!N) puts("SECOND");
			else
				if (N>=a && N<=b)
				{
					puts("FIRST");
					cout << x1-N << endl;
				}
				else puts("DRAW");
		}
		else
		{
			if (n>=a && n<=b) 
			{
				puts("FIRST");
				cout << x2 << endl;
			}
			else puts("DRAW"); 
		}	
}