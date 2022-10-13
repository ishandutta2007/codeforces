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

int main()
{
	int ans=1,loss=0,x,n,cnt=0;
	vector <int> a;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x>=0) cnt++;
		else
			if (loss<2) loss++, cnt++;
			else a.pb(cnt), ans++, loss=cnt=1;
	}
	a.pb(cnt);
	cout << ans << endl;
	rep(i,ans) cout << a[i] << ' ';
}