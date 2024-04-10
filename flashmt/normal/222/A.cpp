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
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000111222
#define maxN 1
using namespace std;

int n,k,a[200100];

int main()
{
	//freopen("","r",stdin); freopen("","w",stdout);
	cin >> n >> k;
	fr(i,1,n) cin >> a[i];
	fr(i,n+1,n*2) a[i]=a[i-(n-k+1)];
	int c=1;
	fr(i,2,n*2)
		if (a[i]==a[i-1])
		{
			if (++c==n) 
			{
				cout << i-n << endl;
				return 0;
			}
		}
		else c=1;
	if (n==1) puts("0");
	else puts("-1");
}