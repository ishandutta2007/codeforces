#include <cstdio>
#include <cassert>
#include <cmath>
#include <set>
#include <map>

using ld = long double;

const ld EPS = 1e-12;
const ld PI = acos((ld)-1);

inline bool equ(const ld& a, const ld& b) {return std::abs(a-b)<EPS;}

struct vec
{
	public:
		ld x, y;
		bool operator == (const vec& o) const {return equ(x, o.x) && equ(y, o.y);}

		vec& operator += (const vec& o) {return x+=o.x, y+=o.y, *this;}
		vec& operator -= (const vec& o) {return x-=o.x, y-=o.y, *this;}
		ld ang() {return atan2(y, x);}

		friend vec operator + (vec a, const vec& b) {return a+=b;}
		friend vec operator - (vec a, const vec& b) {return a-=b;}

		ld operator * (const vec& o) const {return x*o.x+y*o.y;}
		ld mag() const {return hypot(x,y);}
};

const int MN = 1e5+10;

int N, S, P, G, s, p, g, ctr, op;
char t;
vec m, a[MN];
std::multiset<ld> set, val;
std::map<ld, int> map;

int main()
{
	scanf("%d%d%d%d", &S, &P, &G, &N);
	m = vec{(ld)P/(S+P+G), (ld)G/(S+P+G)};
	for(int i=0, x=0, y;i<N;++i)
	{
		scanf(" %c", &t);
		if(t=='A')
		{
			scanf("%d%d%d", &s, &p, &g);
			++x;
			a[x]={(ld)p/(s+p+g), (ld)g/(s+p+g)};
			a[x]-=m;
			if(a[x].mag() < EPS) ++ctr;
			else
			{
				{
					ld v = a[x].ang();
					auto it=map.lower_bound(v-EPS);
					if(it == map.end() || !equ(it->first, v))
						it=map.insert({v, 0}).first;
					if(!it->second++)
					{
						v+=PI;
						if(v>PI)
							v-=2*PI;
						it=map.lower_bound(v-EPS);
						if(it != map.end() && equ(it->first, v) && it->second)
							++op;
					}
				}

				{
					ld v = a[x].ang();
					auto it=set.insert(v);
					auto nx=std::next(it);
					if(it != set.begin())
					{
						auto pr=std::prev(it);
						val.insert(*it-*pr);
						if(nx != set.end())
							val.erase(val.lower_bound(*nx-*pr-EPS));
					}
					if(nx != set.end())
						val.insert(*nx-*it);
				}
			}
		}
		else
		{
			scanf("%d", &y);
			if(a[y].mag() < EPS) --ctr;
			else
			{
				{
					ld v = a[y].ang();
					auto it=map.lower_bound(v-EPS);
					assert(it != map.end() && equ(it->first, v));
					if(!--it->second)
					{
						v+=PI;
						if(v>PI)
							v-=2*PI;
						it=map.lower_bound(v-EPS);
						if(it != map.end() && equ(it->first, v) && it->second)
							--op;
					}
				}

				{
					ld v = a[y].ang();
					auto it=set.lower_bound(v-EPS);
					auto nx=std::next(it);
					if(it != set.begin())
					{
						auto pr=std::prev(it);
						val.erase(val.lower_bound(*it-*pr-EPS));
						if(nx != set.end())
							val.insert(*nx-*pr);
					}
					if(nx != set.end())
						val.erase(val.lower_bound(*nx-*it-EPS));
					set.erase(it);
				}
			}
		}
		if(ctr) printf("1\n");
		else if(op) printf("2\n");
		else if(set.size() >= 3 && *val.rbegin() < PI && (2*PI+*set.begin()-*set.rbegin()) < PI) printf("3\n");
		else printf("0\n");
	}
	return 0;
}