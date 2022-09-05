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
const int INF=1<<29;
const long long LINF=1ll<<61;
ll n,m,k,p,a[1011],b[1011],ca[1000111],cb[1000111];
multiset<ll,greater<ll> > q1,q2;
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		int x;
		scanf("%d",&x);
		a[i]+=x;
		b[j]+=x;
	}
	for(int i=1;i<=n;i++)q1.insert(a[i]);
	for(int i=1;i<=m;i++)q2.insert(b[i]);
	for(int i=1;i<=k;i++)
	{
		ll v1=*q1.begin(),v2=*q2.begin();q1.erase(q1.begin());q2.erase(q2.begin());
		ca[i]=ca[i-1]+v1;
		cb[i]=cb[i-1]+v2;
		q1.insert(v1-p*m);q2.insert(v2-p*n);
	}
	ll ans=100000000;
	ans*=-ans;
//	cout<<ans;
	for(ll i=0;i<=k;i++)ans=max(ans,ca[i]+cb[k-i]-i*(k-i)*p);
	cout<<ans;
// 	system("pause");
	return 0;
}