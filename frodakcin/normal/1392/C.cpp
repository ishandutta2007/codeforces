#include <cstdio>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 2e5+10;

int a[MN], T, N;
ll f;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		f=0;
		for(int i=0;i<N;++i)
		{
			scanf("%d", a+i);
			if(i && a[i-1]>a[i])
				f+=a[i-1]-a[i];
		}
		printf("%lld\n", f);
	}
	return 0;
}