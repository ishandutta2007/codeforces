//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll l,r;
ll getmax(ll x)
{
	ll t=1;
	while(t*10<=x)t*=10;
	return t;
}
int main()
{
	cin>>l>>r;
	ll t=getmax(r),t2=max(l,min(r,t*5));
	cout<<t2*(t*10-1-t2);
	return 0;
}