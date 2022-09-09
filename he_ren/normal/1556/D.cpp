#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

inline int ask_and(int i,int j)
{
	printf("and %d %d\n",i,j);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline int ask_or(int i,int j)
{
	printf("or %d %d\n",i,j);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline void answer(int x)
{
	printf("finish %d\n",x);
	fflush(stdout);
}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline int get_cnt(int x,int y,int k)
{
	if(bdig(y,k)) return 2;
	if(bdig(x,k)) return 1;
	return 0;
}
inline int get_cnt(pii p,int k)
{
	return get_cnt(p.first, p.second, k);
}

inline int calc(pii p1,pii p2,pii p3)
{
	int res = 0;
	for(int t=0; t<=30; ++t)
	{
		int c1 = get_cnt(p1, t), c2 = get_cnt(p2, t), c3 = get_cnt(p3, t);
		for(int i=0; i<=1; ++i)
			for(int j=0; j<=1; ++j)
				for(int k=0; k<=1; ++k)
				{
					if(i+j == c1 && j+k == c2 && i+k == c3)
						res |= k << t;
				}
	}
	return res;
}

pii p[MAXN];
int a[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	for(int i=2; i<=n; ++i)
	{
		int x = ask_or(1,i), y = ask_and(1,i);
		p[i] = make_pair(x,y);
	}
	p[1] = make_pair(ask_or(2,3), ask_and(2,3));
	
	a[1] = calc(p[1], p[2], p[3]);
	for(int i=2; i<=n; ++i)
		a[i] = (p[i].first ^ a[1]) | p[i].second;
	
	sort(a+1,a+n+1);
	
	answer(a[d]);
	return 0;
}