#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,bool> plb;
#define make_pair mp
#define fir first
#define sec second
const int MAXN = 2e5 + 5;

int a[MAXN];
priority_queue<ll,vector<ll>,greater<ll> > q;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int a;
		scanf("%d",&a);
		q.push(a);
	}
	
	ll ans=0;
	if(!(n&1))
	{
		ll x=q.top(); q.pop();
		ll y=q.top(); q.pop();
		
		ll tmp=x+y;
		q.push(tmp);
		ans += tmp;
	}
	while(q.size()>1)
	{
		ll x=q.top(); q.pop();
		ll y=q.top(); q.pop();
		ll z=q.top(); q.pop();
		
		ll tmp=x+y+z;
		q.push(tmp);
		ans += tmp;
	}
	cout<<ans;
	return 0;
}