//IOI2014
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
	srand((unsigned int)time(NULL));
	int n;
	ll lb=-2e9,ub=2e9;
	cin >> n;
	map<string,string>ma;
	ma[">"]="<=";
	ma["<"]=">=";
	ma[">="]="<";
	ma["<="]=">";
	for(int i=0;i<n;i++)
	{
		string s;cin >> s;
		ll x; cin >> x;
		string f; cin >> f;
		if(f=="N") s=ma[s];
		if(s==">") lb=max(lb,x+1);
		if(s=="<") ub=min(ub,x-1);
		if(s==">=") lb=max(lb,x);
		if(s=="<=") ub=min(ub,x);
	}
	if(lb>ub) puts("Impossible");
	else cout << lb << endl;
}