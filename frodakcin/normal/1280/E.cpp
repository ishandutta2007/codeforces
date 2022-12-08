#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

const int MN = 8e4 + 100;
using ll = long long;
const ll INF = 1e18 + 100;

struct Circuit
{
public:
	bool parallel;
	std::vector<Circuit*> comp;//onents
	ll mult;//iplier
	void reset(void)
	{
		parallel = 0;
		mult = 1LL;
		comp.clear();
	}
	Circuit(void)
	{
		reset();
	}
	void calc(void)
	{
		if(parallel)
		{
			mult = 0LL;
			for(Circuit * x : comp)
				mult += x->mult;
		}
		else
		{
			mult = INF;
			for(Circuit * x : comp)
				mult = std::min(mult, x->mult);
		}
	}
	void answer(ll val)
	{
		if(comp.empty())
			return (void)printf(" %lld", val);
		else
			if(parallel)
			{
				for(Circuit * x : comp)
					x->answer(val);
			}
			else
			{
				int i = 0;
				ll tmp = INF;
				for(int j = comp.size()-1;j >= 0;--j)
					if(comp[j]->mult < tmp)
						i = j, tmp = comp[j]->mult;
				for(int j = 0;j < comp.size();++j)
					comp[j]->answer(j==i?val:0LL);
			}
	}
};

const int pool_max = MN * 3;
Circuit pool[pool_max];
int pool_ctr = pool_max;
Circuit * nn(bool multi = false)
{
	Circuit * r = pool + --pool_ctr;
	if(multi)
	{
		char in;
		for(;;)
		{
			scanf(" %c", &in);
			if(in == ')')
				break;
			if(in == '(')
				r->comp.push_back(nn(1));
			else
				r->comp.push_back(nn());
			scanf(" %c", &in);
			if(in == ')')
				break;
			else
				r->parallel = in == 'P';
		}
		r->calc();
	}
	return r;
}

Circuit * root;
int r;

void solve(void)
{
	scanf("%d", &r);
	char fst;
	scanf(" %c", &fst);
	if(fst == '*')
		return (void) printf("REVOLTING %d\n", r);
	root = nn(1);
	// sum = r * sqr(root->mult)
	printf("REVOLTING");
	root->answer(r * root->mult);
	printf("\n");

	for(;pool_ctr < pool_max;++pool_ctr)
		pool[pool_ctr].reset();
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;++i)
		solve();
	return 0;
}