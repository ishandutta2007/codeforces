#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int main(void)
{
	int cur = 1, sum = 1, tp = -1;
	vector< pair<int,uint> > f;
	auto upd = [&] (int x)
	{
		int ntp = -1;
		for(int i=0; i<=tp; ++i)
		{
			uint mask = f[i].second;
			if(bdig(mask,x) || (x == 1 && bdig(mask,0))) continue;
			
			mask >>= x;
			uint t = lowbit(~( mask | (mask >> 1) ));
			mask &= ~(t-1);
			mask |= t;
			mask <<= x;
			
			f[i].second = mask;
			f[++ntp] = f[i];
		}
		tp = ntp;
		if(++tp >= (int)f.size()) f.resize(tp+1);
		f[tp] = {cur, bbit(x)};
		
		cur = sum;
		for(int i=0; i<=tp; ++i)
			if(f[i].second == lowbit(f[i].second))
				add_mod(cur, mod - f[i].first);
		add_mod(sum, cur);
	};
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		static char s[MAXN];
		scanf("%s",s+1);
		for(int i=1; s[i]; ++i)
			upd(s[i] - '0');
		
		printf("%d\n",cur);
	}
	return 0;
}