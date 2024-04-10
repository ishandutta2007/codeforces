//E?Nanndatte?
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
typedef long long ll;
#define mod 1000000009
int main()
{
	long long n,m;
	cin >> n;
	m=n;
	vector<ll>ans;
	for(int i=0;i<=60;i++)
	{
		n=m;
		long long base=1LL<<(i+1);
		base-=3LL;
		if(base/2LL>n) break;
		long long lb=0;
		long long ub=1e10;
		while(ub-lb>1)
		{
			long long mid=(lb+ub)>>1;
			n=m;
			bool flag=false;
			if(2LL*n%mid==0)
			{
				flag=true;
			}
			n*=2LL;
			n/=mid;
			if(flag && n==mid+base)
			{
				if(mid%2!=0) ans.pb(mid*(1LL<<i));
				goto end;
			}
			else
			{
				if(n<mid+base)
				{
					ub=mid;
				}else
				{
					lb=mid;
				}
			}
		}
		end:;
	}
	if(ans.size()==0) puts("-1");
	else 
	{
		for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
	}
	cin >> n;
}