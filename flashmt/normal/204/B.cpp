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

int n,ans=oo;
map <int,int> back,front;
set <int> both;

int main()
{
	int x,y;
	cin >> n;
	rep(i,n) 
	{
		cin >> x >> y;
		if (x!=y) back[y]++;
		front[x]++;
		both.insert(x);
		both.insert(y);
	}
	for (set <int>::iterator it=both.begin();it!=both.end();it++)
		if (back[*it]+front[*it]>=(n+1)/2)
			ans=min(ans,max(0,(n+1)/2-front[*it]));
	
	if (ans==oo) puts("-1");
	else cout << ans << endl;
}