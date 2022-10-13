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
#define base 1000000007
using namespace std;

int k,n;
long long zero[100100],one[100100];
string s,t;

int main()
{
	cin >> s >> t >> k;
	if (!k)
	{
		cout << (s==t) << endl;
		return 0;
	}
	n=sz(s);
	
	zero[0]=1; one[0]=0;
	
	fr(i,1,k)
	{
		zero[i]=one[i-1]*(n-1)%base;
		one[i]=(one[i-1]*(n-2)+zero[i-1])%base;
	}
			
	long long ans=0;
	rep(i,n)
	{
		string u=s;
		rotate(u.begin(),u.begin()+i,u.end());
		if (u==t) ans+=(i?one[k]:zero[k]), ans%=base;
	}
	cout << ans << endl;
}