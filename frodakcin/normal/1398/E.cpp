#include <cstdio>
#include <cassert>
#include <set>

using ll = long long;

ll tot;
int N, L, F;

struct Spell
{
	public:
		int x;
		bool f;
		bool operator < (const Spell& o) const {return x < o.x;}
};
struct set : public std::set<Spell>//all different
{
	public:
		ll sum;
		int fire;
		void ins(int x, bool f)
		{
			sum+=x;
			fire+=f;
			insert({x, f});
		}
		void rem(int x)
		{
			auto it=lower_bound({x, 0});
			assert(it->x==x);
			sum -= x;
			fire -= it->f;
			erase(it);
		}
		Spell remove_min()
		{
			auto it = *begin();
			sum -= it.x;
			fire -= it.f;
			erase(begin());
			return it;
		}
} all;

std::set<int> bad[2];

void add_new()
{
	bool type = *std::prev(bad[1].end())>*std::prev(bad[0].end());
	auto it=std::prev(bad[type].end());
	all.ins(*it, type);
	bad[type].erase(it);
}

int big(std::set<int>& k){return *std::prev(k.end());}

int main()
{
	scanf("%d", &N);
	bad[0].insert(-1);
	bad[1].insert(0);
	for(int i=0, tp, d;i<N;++i)
	{
		scanf("%d%d", &tp, &d);
		tot += d;
		tp^=1;//1 = fire, 0 = lightning
		if(d<0)
		{
			d*=-1;
			if(tp==0) --L;
			else --F;
			if(!all.empty() && d >= all.begin()->x)
				all.rem(d);
			else
				bad[tp].erase(d);
		}
		else
		{
			if(tp==0) ++L;
			else ++F;
			all.ins(d, tp);
		}

		add_new();
		for(;all.size()>L;)
		{
			auto x = all.remove_min();
			bad[x.f].insert(x.x);
		}

		//printf("\t%lld\n", tot);
		//printf("\t%lld\n", all.sum);
		if(all.fire||!L) printf("%lld\n", tot+all.sum);
		else printf("%lld\n", tot+all.sum-all.begin()->x+big(bad[1]));
	}
	return 0;
}