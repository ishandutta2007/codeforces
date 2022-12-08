#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using ld = double;//long double if necessary
const ld PI = acos((ld)-1), EPS=1e-10;

bool equ(ld a, ld b){return std::abs(a-b)<EPS;}
const int MN = 5e5+10;

struct vec
{
public:
	int x,y;
	ld ang, mag;
	void in()
	{
		scanf("%d%d", &x, &y);
		if(equ(y, 0) && equ(x, 0))
			ang = -10*PI;
		else
			ang = atan2((ld)y, (ld)x);
		mag = hypot((ld)x, (ld)y);
	}
	bool operator < (const vec& o) const
	{
		if(equ(ang, o.ang))
			return mag > o.mag;
		else
			return ang < o.ang;
	}
} a[MN];
int N, K, b[MN], R, V;
ld v[MN];
bool rem[MN];

ld ans,cur,tot;
ld eval()
{
	ld ca=0;
	for(int i=1,j,n,c=1,d;i<N;i=j)
	{
		d=0;
		for(j=i;j<N&&equ(a[n=b[j]].ang, a[b[i]].ang);++j)
		{
			if(rem[n]) continue;
			//printf("USE %d\n", n+1);
			ca+=tot+(c-2*d)*a[n].mag;
			++c, ++d;
			tot+=a[n].mag;
		}
	}
	return ca;
}
int main(void)
{
	scanf("%d%d", &N, &K);R=N-K;
	for(int i=0;i<N;++i)
		a[i].in(), b[i]=i;
	if(K <= 1) return printf("0\n"),0;
	std::sort(b, b+N, [](int x, int y){return a[x]<a[y];});
	if(N==K)
		return printf("%.9Lg\n", eval()), 0;
	//case: remove 0
	for(int i=1,j,x,n;i<N;i=j)
		for(j=i;j<N&&equ(a[n=b[j]].ang, a[b[i]].ang);++j)
			v[V++] = (K-1-2*(j-i))*a[n].mag;
	std::nth_element(v, v+K, v+V, std::greater<ld>());
	for(int i=0;i<K;++i)
		ans+=v[i];//remove zero case

	//delete from line case
	for(int i=1,j;i<N;i=j)
	{
		for(j=i+1;j<N&&equ(a[b[j]].ang, a[b[i]].ang);++j);
		//len = j-i
		int o=N-(j-i);
		if(K>=o*2)
		{
			//perform line case;
			for(int k=o+(N-2*o-R)/2,mk=k+R;k<mk;++k)
				rem[b[i+k]] = 1;
			return printf("%.9g\n", eval()), 0;
		}
	}

	printf("%.9g\n", ans);
	return 0;
}