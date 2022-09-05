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
const ll MOD=1e9+7;
ll a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin>>a>>b;
	ll ans=0;ll t=(1+a)*a/2%MOD;
	for(int i=1;i<b;i++)//i=x%b
	{
		ans=(ans+t*b%MOD*i%MOD+a*i%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}