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

int n,m,k,a[10010],per;

int main()
{
	int i,mn=100001;
	cin >> n >> m >> k;
	fr(i,1,n) scanf("%d",&a[i]);
	if (n%2==0) 
	{
		cout << 0 << endl;
		return 0;
	}
	fr(i,1,n) 
		if (i%2) mn=min(mn,a[i]);
	per=m/((n+1)/2);
	long long re=min(1LL*per*k,1LL*mn);
	cout << re << endl;
	return 0;
}