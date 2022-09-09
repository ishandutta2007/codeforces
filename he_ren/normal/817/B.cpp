#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
typedef long long ll;
const int MAXN = 1e5 + 5;
using namespace std;

int a[MAXN];
map<int,int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) ++t[a[i]];
	unique(a+1,a+n+1);
	
	ll x=t[a[1]];
	if(x>=3)
	{
		cout<<x*(x-1)*(x-2)/6;
		return 0;
	}
	
	if(x==2)
	{
		cout<<t[a[2]];
		return 0;
	}
	
	ll y=t[a[2]];
	if(y>=2)
	{
		cout<<y*(y-1)/2;
		return 0;
	}
	
	cout<<t[a[3]];
	return 0;
}