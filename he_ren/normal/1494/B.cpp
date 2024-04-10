#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define lowbit(x) ((x)&-(x))

inline int get_num1(int x)
{
	int res = 0;
	while(x) ++res, x ^= lowbit(x);
	return res;
}

int n;
inline bool chk(int x){ return x >= 0 && x <= n-2;}

void solve(void)
{
	int a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	
	int all = (1<<4) - 1;
	for(int mask=0; mask<=all; ++mask)
	{
		int aa = a - get_num1(mask & (8 + 4));
		int bb = b - get_num1(mask & (4 + 1));
		int cc = c - get_num1(mask & (2 + 1));
		int dd = d - get_num1(mask & (8 + 2));
		if(chk(aa) && chk(bb) && chk(cc) && chk(dd))
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}