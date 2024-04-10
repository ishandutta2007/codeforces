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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int n,a,b,c,d,e,f;
	cin >> n >> a >> b >> c >> d >> e >> f;
	vector<int>beg;
	for(int i=0;i<a;i++) beg.pb(0);
	for(int i=a;i<n;i++) beg.pb(beg[i-a]+d);
	vector<int>beg2;
	for(int i=0;i<b;i++) beg2.pb(beg[i]+d);
	for(int i=b;i<n;i++) beg2.pb(max(beg[i]+d,beg2[i-b]+e));
	vector<int>beg3;
	for(int i=0;i<c;i++) beg3.pb(beg2[i]+e);
	for(int i=c;i<n;i++) beg3.pb(max(beg2[i]+e,beg3[i-c]+f));
	cout << beg3[beg3.size()-1]+f << endl;
}