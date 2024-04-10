#include <cstdio>
#include <cassert>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 3e5+10, MS = 5e5+10;

int N, minn=MS, maxn, minb=MS, maxb, min=-1, max=MS, mind, maxd, X, Y;
char s[MS];
struct Point
{
	public:
		int n,b;
} a[MN];

bool test(int R)
{
	minn=0, maxn=MS;
	minb=0, maxb=MS;
	mind=-MS, maxd=MS;//n - b == X - Y
	for(int i=0;i<N;++i)
	{
		ckmin(maxn, a[i].n+R);
		ckmax(minn, a[i].n-R);
		ckmin(maxb, a[i].b+R);
		ckmax(minb, a[i].b-R);
		ckmin(maxd, a[i].n-a[i].b+R);
		ckmax(mind, a[i].n-a[i].b-R);
	}
	/*
	if(R==12)
	{
		printf("N: %d %d\n", minn, maxn);
		printf("B: %d %d\n", minb, maxb);
		printf("D: %d %d\n", mind, maxd);
	}
	*/
	if(minn>maxn) return 0;
	if(minb>maxb) return 0;
	if(mind>maxd) return 0;
	if(mind>maxn-minb) return 0;
	if(minn-maxb>maxd) return 0;

	//find answer
		//printf("D: %d %d %d\n", minn-minb, mind, maxd);
	if(minn-minb<mind)
		Y=minb, X=Y+mind;
	else if(minn-minb>maxd)
		X=minn, Y=X-maxd;
	else
		X=minn, Y=minb;
	return 1;
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		int n=0,b=0;
		scanf(" %s", s);
		for(int j=0;s[j];++j)
			if(s[j]=='N')
				++n;
			else
				++b;
		a[i]={n,b};
		//printf("%d, %d\n", n, b);
	}
	for(;max-min>1;)
	{
		int m=min+(max-min)/2;
		if(test(m)) max=m;
		else min=m;
	}
	printf("%d\n", max);
	assert(test(max));
	for(int i=0;i<Y;++i) printf("B");
	for(int i=0;i<X;++i) printf("N");
	if(X==0&&Y==0) printf("NB");
	printf("\n");
	return 0;
}