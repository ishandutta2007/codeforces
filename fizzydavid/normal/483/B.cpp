//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll cnt1,cnt2,x,y;
bool check(ll m)
{
	ll cnty=m/x-m/x/y;
	ll cntx=m/y-m/x/y;
	ll r=m-(m/x+m/y-m/x/y);
	return r>=max(0ll,cnt1-cntx)+max(0ll,cnt2-cnty);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>cnt1>>cnt2>>x>>y;
	ll l=cnt1+cnt2,r=1ll<<50,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}