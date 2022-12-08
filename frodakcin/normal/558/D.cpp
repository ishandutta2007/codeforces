#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using ll = long long;

int H, Q, V;

struct Rule
{
	public:
		ll t; int d;
		bool operator < (const Rule& o) const {return t < o.t;}
};
std::vector<Rule> a;
struct Range
{
	public:
		ll l,r;
};
std::vector<Range> ans;

int main()
{
	scanf("%d%d", &H, &Q);
	for(int i=0;i<Q;++i)
	{
		int h, ans;
		ll L, R;
		scanf("%d%lld%lld%d", &h, &L, &R, &ans);
		V+=ans;
		L<<=H-h;
		++R;
		R<<=H-h;
		a.push_back({L, ans*2-1});
		a.push_back({R, 1-ans*2});
	}
	a.push_back({1ll<<H-1,0});
	a.push_back({1ll<<H,0});
	std::sort(a.begin(), a.end());
	for(int i=0,j,c=0;i<a.size();i=j)
	{
		for(j=i;j<a.size() && a[i].t==a[j].t;++j) c+=a[j].d;
		if(j==a.size())
		{
			assert(c==0);
			break;
		}
		//printf("%lld->%lld: %d/%d\n", a[i].t, a[j].t, c, V);
		if(c==V)
			ans.push_back({a[i].t, a[j].t});
	}
	//for(auto x:ans) printf("%lld->%lld\n", x.l, x.r);
	if(ans.empty())
		printf("Game cheated!\n");
	else if(ans.size()>1||ans[0].r-ans[0].l>1)
			printf("Data not sufficient!\n");
	else
		printf("%lld\n", ans[0].l);
	return 0;
}