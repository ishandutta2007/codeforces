#include <cstdio>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int INF = 1e9+10;
const int MN = 2e5+10;


int a[MN], T, N;
ll K;

void apply()
{
	int x=-INF;
	for(int i=0;i<N;++i) ckmax(x, a[i]);
	for(int i=0;i<N;++i) a[i]=x-a[i];
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%lld", &N, &K);
		for(int i=0;i<N;++i)
			scanf("%d", a+i);
		int dif=0;
		apply(), --K;
		if(K&1) apply();
		for(int i=0;i<N;++i)
			printf("%d%c", a[i], " \n"[i+1==N]);
	}
	return 0;
}