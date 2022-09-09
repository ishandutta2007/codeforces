#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

string s[MAXN];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		cin>>s[i];
	
	sort(s+1,s+n+1);
	
	ll tot = (1ll<<m) - n;
	ll less = (tot+1)/2 - 1;
	
	string ans(m,'0');
	ll cnt = 0;
	for(int k=0; k<m; ++k)
	{
		ans[k]='1';
		ll tmp = cnt + (1ll<<(m-k-1));
		
		for(int i=1; i<=n && s[i]<ans; ++i) --tmp;
		
		if(tmp>less) ans[k]='0';
		else ans[k]='1', cnt += (1ll<<(m-k-1));
	}
	cout<<ans<<endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}