#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b < a ? a = b, 1 : 0;}

const int MV = 3e6 + 100;
const int INF = 10000;
typedef long long ll;

int cnt;
int vals[MV], best[MV];
int primes[30], pc;
bool can[MV];
int l, r, p;
void brute(int pn = 0, ll val = 1LL)
{
	if(pn == pc)
		vals[cnt] = val, best[cnt] = INF, cnt++;
	else
		for(;val <= r;val *= primes[pn])
			brute(pn + 1, val);
}
int main(void)
{
	scanf("%d%d%d", &l, &r, &p);
	for(int i = 2;i < 100;i++)
	{
		bool works = 1;
		for(int j = 2;j < i;j++)
			if(!(i%j))
				works = 0;
		if(works)
			primes[pc++] = i;
	}
	brute();
	sort(vals, vals + cnt);
	best[0] = 0;
	for(int v = 2;v <= p;v++)
		for(int i = 0, e = r/v, j = 1;vals[i] <= e;i++)
		{
			if(best[i] + v >= p)
				continue;
			for(;vals[j] < v*vals[i];j++);
			mn(best[j], best[i] + 1);
			can[j] = 1;
		}
	int f = 0;
	for(int i = 0;i < cnt;i++)
		if(can[i] && vals[i] >= l)
			f++;
	printf("%d\n", f);
	return 0;
}