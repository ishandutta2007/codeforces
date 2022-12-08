#include <cstdio>
#include <cassert>
#include <vector>
#include <array>
#include <algorithm>

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

bool ckmin(auto& a, const auto& b) {return b<a?a=b,1:0;}
bool ckmax(auto& a, const auto& b) {return b>a?a=b,1:0;}

using ll = long long;

int eval(int n1, int n2)
{
	assert((n1+2*n2)%3==0);
	if(n2 < n1)
		return n2+(n1-n2)*2/3;
	else
		return n2; // n1 + (n2-n1)
}

void solve()
{
	int N;
	scanf("%d", &N);
	std::vector<int> p(N);
	for(int& x:p) scanf("%d", &x), --x;

	{
		ll v=1;
		for(int i=N;;i-=3)
			if(i>=6)
				v=v*3%MOD;
			else
			{
				if(i==5) v=v*6%MOD;
				else v=v*i%MOD;
				break;
			}
		printf("%lld ", v); // easy part ?
	}

	std::vector<int> sz;
	std::vector<char> vis(N, 0);
	for(int i=0;i<N;++i)
		if(!vis[i])
		{
			int v=0;
			for(int x=i;;x=p[x])
			{
				if(vis[x]) break;
				vis[x]=1;
				++v;
			}
			sz.push_back(v);
		}

	std::sort(sz.begin(), sz.end());
	std::vector<int> unq=sz;
	unq.resize(std::distance(unq.begin(), std::unique(unq.begin(), unq.end())));
	std::vector<int> cnt(unq.size());

	{
		int i=0;
		for(int x:sz)
		{
			if(unq[i] < x) ++i; // wont overflow to inf. Also, if instead of while should be ok
			++cnt[i];
		}
	}

	int cur=0, n1=0, n2=0, ans=INF;
	auto modify=[&](int v, int c)
	{
		if(v==0) return;
		cur += (v-1)/3*c;
		if(v%3==1) n1+=c;
		if(v%3==2) n2+=c;
	};
	for(int i=0;i<unq.size();++i)
		modify(unq[i], cnt[i]);

	if(N%3==0)
		ans=cur+eval(n1, n2);
	else if(N%3==2)
	{
		//1-1
		if(n1>=2) ckmin(ans, cur+eval(n1-2, n2)+1);
		for(int i=0;i<unq.size();++i)
			if(unq[i]>=2) 
			{
				modify(unq[i], -1); modify(unq[i]-2, 1); if(unq[i]>2) ++cur;
				ckmin(ans, cur+eval(n1, n2));
				modify(unq[i]-2, -1); modify(unq[i], 1); if(unq[i]>2) --cur;
			}
	}
	else
	{
		//1-1-1-1
		if(n1>=4) ckmin(ans, cur+eval(n1-4, n2)+2);
		//1-1-2
		if(n1>=2 && n2>=1) ckmin(ans, cur+eval(n1-2, n2-1)+1);
		//1-3
		if(n1>=1 && unq.back()>=3)
			ckmin(ans, cur+eval(n1-1, n2)+1);
		//single group of 4
		for(int i=0;i<unq.size();++i)
			if(unq[i] >= 4)
			{
				modify(unq[i], -1); modify(unq[i]-4, 1); if(unq[i]>4) ++cur;
				ckmin(ans, cur+eval(n1, n2));
				modify(unq[i]-4, -1); modify(unq[i], 1); if(unq[i]>4) --cur;
			}
		//2 groups of 2
		for(int i=0;i<unq.size();++i)
			if(unq[i] >= 2)
			{
				--cnt[i]; modify(unq[i], -1); modify(unq[i]-2, 1); if(unq[i]>2) ++cur;
				for(int j=i;j<unq.size();++j)
					if(unq[j] >= 2 && cnt[j] > 0)
					{
						modify(unq[j], -1); modify(unq[j]-2, 1); if(unq[j]>2) ++cur;
						ckmin(ans, cur+eval(n1, n2));
						modify(unq[j]-2, -1); modify(unq[j], 1); if(unq[j]>2) --cur;
					}
				++cnt[i]; modify(unq[i]-2, -1); modify(unq[i], 1); if(unq[i]>2) --cur;
			}
	}

	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}