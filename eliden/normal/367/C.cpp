#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll k=1;
	while((k%2==0&&k*(k+1)/2+1<=n)||(k%2==1 && (k+1)*(k+1)/2<=n))
		++k;
	vector<ll> w;
	w.resize(m);
	rep(i,0,m)
	{
		int q;
		cin >> q >> w[i];
		w[i]=-w[i];
	}
	sort(w.begin(),w.end());
	k = min(k,m);
	ll t = 0;
	rep(i,0,k)
		t-=w[i];
	cout<<t<<endl;	
}