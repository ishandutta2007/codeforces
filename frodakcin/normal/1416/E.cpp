#include <cstdio>
#include <cassert>
#include <set>
#include <functional>

using ll = long long;

const int MN = 5e5+10;

struct Range
{
	public:
		mutable ll l, r;//inclusive, inclusive
		bool operator < (const Range& o) const {return l < o.l;}
};

std::set<Range> set;
int N, a[MN], T, f;
ll c;
bool sign;

void check_pos()
{
	if(sign)//negative. Remove everything >= c
	{
		for(auto it=set.end();it != set.begin();)
		{
			--it;
			if(it->l >= c)
			{
				it=set.erase(it);
				continue;
			}
			else if(it->r >= c)
				it->r=c-1;
			break;
		}
	}
	else//positive. Remove everything <= -c
	{
		for(auto it=set.begin();it!=set.end();)
		{
			if(it->r<=-c)
			{
				it=set.erase(it);
				continue;
			}
			else if(it->l <= -c)
				it->l=-c+1;
			break;
		}
	}
}

bool find(ll v)
{
	v = (1-2*sign)*(v-c);//convert v
	auto it=set.upper_bound({v,-1});
	if(it == set.begin()) return 0;
	--it;
	assert(it->l <= v);
	return it->r >= v;
}

void ins(ll v)
{
	v = (1-2*sign)*(v-c);//convert v
	set.insert({v,v});
}

void solve()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	for(int i=0;i<N;++i)
	{
		c = a[i]-c, sign^=1;

		check_pos();
		if(set.empty())
		{
			sign=0, c=0;
			if(a[i]&1)
				set.insert({1, a[i]-1}), f+=2;
			else
				set.insert({a[i]/2, a[i]/2}), ++f;
		}
		else
			if(!(a[i]&1) && find(a[i]/2))
			{
				set.clear();
				sign=0, c=0;
				set.insert({a[i]/2, a[i]/2});
			}
			else
			{
				++f;
				if(!(a[i]&1))
					ins(a[i]/2);
			}
	}
	printf("%d\n", f);
}

void reset()
{
	f=0;
	set.clear();
	sign=0, c=0;
}

int main()
{
	scanf("%d", &T);
	while(T--) solve(), reset();
	return 0;
}