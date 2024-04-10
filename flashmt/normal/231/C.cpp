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

int n,k,a[100100];

int ok(int c,int &which)
{
	long long s=0;
	rep(i,c) s+=a[i];
	
	fr(i,c-1,n-1)
	{
		if (1LL*a[i]*c-s<=k) 
		{
			which=a[i];
			return 1;
		}
		s+=a[i+1]-a[i-c+1];
	}
	return 0;
}

int main()
{
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	sort(a,a+n);
	
	int low=1,high=n,ans,which;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if (ok(mid,which)) ans=mid, low=mid+1;
		else high=mid-1;
	}
	
	ok(ans,which);
	cout << ans << ' ' << which << endl;
}