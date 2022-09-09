#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f;

char s[MAXN];

int main(void)
{
	int x, y;
	scanf("%s%d%d",s+1,&x,&y);
	int n = strlen(s+1);
	if(x<y) swap(x,y), reverse(s+1,s+n+1);
	
	ll res = 0;
	int cnt[2] = {0,0};
	for(int i=1; i<=n; ++i) if(s[i] != '?')
	{
		if(s[i] == '1')
			res += (ll)cnt[0] * x;
		else
			res += (ll)cnt[1] * y;
		++cnt[s[i] - '0'];
	}
	int tot[2] = {cnt[0], cnt[1]};
	cnt[0] = cnt[1] = 0;
	
	vector<ll> p, q;//p: 1, q: 0
	for(int i=1; i<=n; ++i)
	{
		if(s[i] != '?'){ ++cnt[s[i] - '0']; continue;}
		p.push_back((ll)cnt[0] * x + (ll)(tot[0] - cnt[0]) * y);
		q.push_back((ll)cnt[1] * y + (ll)(tot[1] - cnt[1]) * x);
	}
	for(int i=1; i<(int)p.size(); ++i)
		p[i] += p[i-1], q[i] += q[i-1];
	
	ll ans = linf;
	if(p.size())
	{
		for(int i=0; i<=(int)p.size(); ++i)
		{
			ll tmp = 0;
			if(i>0) tmp += p[i-1] + (q.back() - q[i-1]);
			else tmp = q.back();
			ans = min(ans, tmp + (ll)i * ((int)p.size() - i) * y);
		}
	}
	else ans = 0;
	
	printf("%lld",ans + res);
	return 0;
}