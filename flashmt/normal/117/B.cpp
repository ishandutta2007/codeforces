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

int d[10000010];

int main()
{
	int a,b,mod;
	cin >> a >> b >> mod;
	a=min(a,mod); b=min(b,mod);
	for (int i=0;i<=b;i++) d[i%mod]=1;
	for (int i=0;i<=a;i++)
	{
		long long rem=1000000000LL*i%mod;
		if (rem) rem=mod-rem;
		if (!d[rem]) 
		{
			cout << "1 ";
			int t=i,l=0;
			if (!t) l=1;
			else
				while (t) t/=10, l++;
			for (int j=l+1;j<=9;j++) cout << 0;
			cout << i << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}