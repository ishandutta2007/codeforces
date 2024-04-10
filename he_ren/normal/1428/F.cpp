#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

char s[MAXN];

inline int calc_len(const pii &seg){ return seg.second - seg.first + 1;}

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	vector<pii> seg;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i] == s[j]) ++j;
		if(s[i] == '1')
			seg.push_back(make_pair(i,j-1));
	}
	
	if(seg.empty()) return printf("0"), 0;
	
	static int f[MAXN];
	
	ll ans = 0;
	
	stack<pii> sta;
	
	for(int i=0; i<(int)seg.size(); ++i)
	{
		int cur_len = calc_len(seg[i]);
		
		while(!sta.empty() && calc_len(sta.top()) < cur_len)
			sta.pop();
		
		if(sta.empty()) f[i] = seg[i].first;
		else f[i] = seg[i].first - (sta.top().second - cur_len) - 1;
		
		sta.push(seg[i]);
		
		for(int j=1; j<cur_len; ++j)
			ans += (ll)j * (cur_len-j+1);
	}
	
	while(!sta.empty()) sta.pop();
	
	for(int i=(int)seg.size()-1; i>=0; --i)
	{
		int cur_len = calc_len(seg[i]);
		
		for(int j=1; j<cur_len; ++j)
		{
			while(!sta.empty() && calc_len(sta.top()) <= j)
				sta.pop();
			
			if(sta.empty()) ans += (ll)j * (n - seg[i].second);
			else ans += (ll)j * (sta.top().first + j - seg[i].second - 1);
		}
		
		while(!sta.empty() && calc_len(sta.top()) <= cur_len)
			sta.pop();
		
		ll mul = (ll)f[i] * cur_len;
		
		if(sta.empty()) ans += mul * (n - seg[i].second + 1);
		else ans += mul * (sta.top().first + cur_len - seg[i].second);
		
		sta.push(seg[i]);
	}
	
	while(!sta.empty()) sta.pop();
	
	for(int i=0; i<(int)seg.size(); ++i)
	{
		int cur_len = calc_len(seg[i]);
		
		for(int j=1; j<cur_len; ++j)
		{
			while(!sta.empty() && calc_len(sta.top()) < j)
				sta.pop();
			
			if(sta.empty()) ans += (ll)j * (seg[i].first - 1);
			else ans += (ll)j * (seg[i].first - (sta.top().second - j + 1) - 1);
		}
		
		while(!sta.empty() && calc_len(sta.top()) <= cur_len)
			sta.pop();
		sta.push(seg[i]);
	}
	
	printf("%lld",ans);
	return 0;
}