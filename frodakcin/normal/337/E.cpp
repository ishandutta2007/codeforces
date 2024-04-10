#include <cstdio>
#include <algorithm>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;};
template<typename T> bool ckmin(T& a, const T& b){return a>b?a=b,1:0;};

using ll = long long;

const int MN = 10;
const ll INF = 1e15;

int N, f=1e9, p[MN], c[MN], off;
ll a[MN], v[MN];

ll mul(ll a, ll b){return a<(INF+b-1)/b?a*b:INF;}

void brute(int n=0)
{
	if(n==N)
	{
		for(int i=0;i<N;++i) v[i]=1;
		int x=0, t=0;
		for(int i=0;i<N;++i)
		{
			if(p[i]!=i)
				v[p[i]]=mul(v[p[i]], a[i]);
			if(a[i]%v[i])
			{
				t=-1;
				break;
			}
			if(p[i]==i)
				t+=c[i], ++x;
		}
		if(~t) ckmin(f, t+(x>1));
		return;
	}
	for(int i=n;i<N;++i)
		p[n]=i, brute(n+1);
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%lld", a+i);
	std::sort(a, a+N);
	N=std::unique(a, a+N)-a;
	for(int i=0;i<N;++i)
	{
		c[i]=0;
		ll v=a[i];
		for(ll j=2;j*j<=v;++j)
			if(v%j==0)
			{
				++c[i];
				for(v/=j;v%j==0;v/=j)
					++c[i];
			}
		if(v>1) ++c[i];
		if(c[i]>1) ++off;
		//printf("%lld: %d\n", a[i], c[i]);
	}
	brute();
	printf("%d\n", f+off);
	return 0;
}