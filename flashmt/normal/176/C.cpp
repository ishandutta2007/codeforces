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

int win(int m,int n)
{
	if (m>n) swap(m,n);
	if (m<4) return n<6;
	if (m==4) return n==4;
	return 0;
}

int main()
{
	int m,n,x,y,xx,yy;
	cin >> m >> n >> x >> y >> xx >> yy;
	m=abs(x-xx)+1;
	n=abs(y-yy)+1;
	cout << (win(m,n)?"First":"Second") << endl;
}