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

int n;
string a,b;
long long sa[26],sb[26];
double match;

int main()
{
	cin >> n >> a >> b;
	rep(i,n)
	{
		int x=a[i]-'A',y=b[i]-'A';
		match+=1LL*(n-i)*(sa[y]+sb[x]);
		if (x==y) match+=1LL*(n-i)*(i+1);
		sa[x]+=i+1;
		sb[y]+=i+1;
	}
	
	long long total=0;
	fr(i,1,n) total+=1LL*i*i;
	printf("%.12lf\n",match/total);
}