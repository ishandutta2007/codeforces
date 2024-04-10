#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll a[100005];
ll b[100005];
int main()
{
	string x,y;
	cin >> x >> y;
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	while(x.size() && x[x.size()-1] == '0') x.resize(x.size()-1);
	while(y.size() && y[y.size()-1] == '0') y.resize(y.size()-1);
	if(x.empty()) x = "0";
	if(y.empty()) y = "0";
	if(x == "0" && y == "0")
	{
		puts("="); return 0;
	}
	else if(x == "0")
	{
		puts("<"); return 0;
	}
	else if(y == "0")
	{
		puts(">"); return 0;
	}
	int ab = max((int)x.size(),(int)y.size());
	if(ab == 1)
	{
		puts("="); return 0;
	}
	while(x.size() != ab) x.pb('0');
	while(y.size() != ab) y.pb('0');
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	if(x[0] == '1' && y[0] == '0' && y[1] == '0')
	{
		puts(">"); return 0;
	}
	if(y[0] == '1' && x[0] == '0' && x[1] == '0')
	{
		puts("<"); return 0;
	}
	for(int i=0;i<x.size();i++) a[i] = (ll)(x[i]-'0');
	for(int i=0;i<y.size();i++) b[i] = (ll)(y[i]-'0');
	ll aa = a[0],bb = a[1], cc= b[0] , dd = b[1];
	int cur = 2;
	while(cur < x.size())
	{
		bb += aa;
		aa += a[cur];
		swap(aa,bb);
		dd += cc;
		cc += b[cur];
		swap(dd,cc);
		if(aa > cc && bb >= dd)
		{
			puts(">"); return 0;
		}
		if(aa < cc && bb <= dd)
		{
			puts("<"); return 0;
		}
		ll ee = min(aa,cc);
		ll ff = min(bb,dd);
		aa -= ee;
		cc -= ee;
		bb -= ff;
		dd -= ff;
		cur++;
	}
	if(aa == cc && bb == dd)
	{
		puts("=");
		return 0;
	}
	double up = (double)aa*(sqrt(5)+1.0)/2 + (double)bb;
	double dw = (double)cc*(sqrt(5)+1.0)/2 + (double)dd;
	puts(up < dw?"<":">");
}