#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MN = 5e5 + 100;
int N, a[MN];
using vi = vector<int>;
#define pb push_back
#define sz size()
#define bk back()
#define pob pop_back()
ll f;
vi b;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%d", a + i);
	for(int i = 0;i < N;b.pb(a[i++]))
		for(;b.sz>1&&b.bk<=min(a[i], b[b.sz-2]);b.pob)
			f += min(a[i], b[b.sz-2]);
	if(b.sz <= 2)
		return printf("%lld\n", f), 0;
	for(int i = 1;i < b.sz-1;i++)
		f += min(b[i-1], b[i+1]);
	printf("%lld\n", f);
	return 0;
}