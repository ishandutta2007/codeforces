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
const int INF=1<<28;
const long long LINF=1ll<<61;
const long long MOD=1000000007;
ll pow(ll x)
{
	ll ans=1,b=2;
	while(x>0)
	{
		if(x&1)ans=ans*b%MOD;
		x=x>>1;
		b=b*b%MOD;
	}
	return ans;
}
ll n;
int main()
{
	cin>>n;
	if(n==0)puts("1");else cout<<(pow(n-1)+pow(n+n-1))%MOD;
// 	system("pause");
	return 0;
}