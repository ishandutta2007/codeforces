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
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
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

int a,b,n,gcd[111][111];

int main()
{
	fr(i,0,100) gcd[0][i]=gcd[i][0]=i;
	fr(i,1,100) fr(j,i,100) gcd[i][j]=gcd[j][i]=(i==j?i:gcd[i][j-i]);
	cin >> a >> b >> n;
	int re=0;
	while (1)
	{
		int x=gcd[n][(re?b:a)];
		if (n<x) break;
		n-=x;
		re^=1;
	}
	cout << 1-re << endl;
	return 0;
}