#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 3e5 + 10;

int n,p,k;
pr a[maxn];

ll val(pr x)
{
	return (((ll)x.fir*k-x.sec)%p+p)%p;
}
int pw4(ll x){return x*x%p*x%p*x%p;}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif
	
	scanf("%d%d%d",&n,&p,&k);int i;
	for(i=0;i<n;i++) scanf("%d",&a[i].fir);
	for(i=0;i<n;i++) a[i].sec=pw4(a[i].fir);

	map<ll,ll> mp;
	for(i=0;i<n;i++) mp[val(a[i])]++;

	map<ll,ll>::iterator it;ll fans=0;
	for(it=mp.begin();it!=mp.end();it++) fans+=it->sec*(it->sec-1)/2;

	cout<<fans<<endl;

	return 0;
}