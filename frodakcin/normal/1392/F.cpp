#include <cstdio>
#include <cassert>
#include <cstring>
#include <set>
#include <functional>

using ll = long long;

const int MN = 1e6+10;

int N;
ll a[MN], base;
std::set<int, std::greater<int> > equ;//a[i] and a[i+1] are equal

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;++i) scanf("%lld", a+i);
	base=a[1];
	for(int i=2;i<=N;++i)
	{
		ll v=a[i]-(base+i-2-equ.size());
		//printf("%d: V: %lld\n", i, v);
		//printf("\tequ: %lld - %d\n", a[i], base+i-2-equ.size());
		equ.insert(i-1);
		for(;!equ.empty();)
		{
			int x=*equ.begin();
			equ.erase(equ.begin());
			if(v>i-x)
				v-=i-x;
			else
			{
				x+=(int)v;
				if(x<i)//else equality case: v == i-x
					equ.insert(x);
				v=0;
				break;
			}
		}
		if(v && equ.empty())
		{
			base += v/i;
			v%=i;
			if(v) ++base, equ.insert((int)v);
		}
		//printf("\tbase: %lld\n", base);
		//printf("\tEQU: "); for(auto x: equ) printf(" %d", x); printf("\n");
	}
	{
		ll c=base;
		auto it=equ.rbegin();
		for(int i=1;i<=N;++i, ++c)
		{
			if(it != equ.rend() && i-1==*it)
				--c, ++it;
			printf("%lld%c", c, " \n"[i==N]);
		}
	}
	return 0;
}