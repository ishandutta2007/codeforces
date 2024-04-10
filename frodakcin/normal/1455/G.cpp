#include <cstdio>
#include <map>
#include <set>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

int N, S;

struct Data
{
	public:
		std::map<int, ll> map;
		std::multiset<ll> set;
		ll off;

		Data(int x=0, ll v=0)
		{
			off=0;
			set.insert(v);
			map.insert({x,v});
		}

		void setv(int y, int v)
		{
			if(y==S) off += v;
			else
			{
				ll t=off+*set.begin();
				off += v;

				auto it=map.find(y);
				if(it != map.end())
				{
					set.erase(set.find(it->second));
					it->second = t-off; // ckmin shouldn't be necessary ?
					set.insert(t-off);
				}
				else
					map.insert({y, t-off}), set.insert(t-off);
			}
		}

		void remove(int v)
		{
			auto it=map.find(v);
			set.erase(set.find(it->second));
			map.erase(it);
		}

		void merge(Data& o)
		{
			if(map.size() < o.map.size())
			{
				map.swap(o.map);
				set.swap(o.set);
				std::swap(off, o.off);
			}
			for(auto x:o.map)
			{
				ll v=x.second+o.off-off;
				auto it=map.find(x.first);
				if(it==map.end())
				{
					map.insert({x.first, v});
					set.insert(v);
				}
				else if(v<it->second)
				{
					set.erase(set.find(it->second));
					it->second=v;
					set.insert(v);
				}
			}
			o.map.clear();
			o.set.clear();
		}
};

char s[10];
void solve(Data* n)
{
	for(;N>0;)
	{
		scanf(" %s", s);--N;
		if(s[0]=='e') return;
		if(s[0]=='s')
		{
			int y, v;
			scanf("%d%d", &y, &v);
			if(n)
				n->setv(y, v);
		}
		if(s[0]=='i')
		{
			int y;
			scanf("%d", &y);

			if(!n) solve(nullptr);
			else
			{
				auto it=n->map.find(y);
				if(it == n->map.end())
					solve(nullptr);
				else
				{
					n->remove(y);
					Data v(y, it->second+n->off);
					solve(&v);
					n->merge(v);
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &S);
	Data x;
	solve(&x);
	printf("%lld\n", *x.set.begin()+x.off);
	return 0;
}