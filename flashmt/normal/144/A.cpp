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
#define oo 1000111222
#define maxN 1
using namespace std;

int ans,n,a[111],mx,mn=101;

int main()
{
	cin >> n;
	rep(i,n) cin >> a[i], mx=max(mx,a[i]), mn=min(mn,a[i]);
	while (a[0]!=mx)
		rep(i,n)
			if (a[i]==mx) 
			{
				swap(a[i],a[i-1]);
				ans++;
				break;
			}
	while (a[n-1]!=mn)
		repp(i,n)
			if (a[i]==mn)
			{
				swap(a[i],a[i+1]);
				ans++;
				break;
			}
	cout << ans << endl;
}