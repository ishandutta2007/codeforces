#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using ld = double;
using ll = long long;
ld pi = acos((ld)-1);
struct vec
{
public:
	int x,y;
	void in(){scanf("%d%d", &x, &y);}
	vec& operator -= (vec b){return x-=b.x, y-=b.y, *this;}
	friend vec operator - (vec a, vec b){return a-=b;}
} a[10000];
struct lin
{
	ld x;
	int i,j;
	bool operator < (lin o) const {return x < o.x;}
};
std::vector<lin> b;
int N;
std::vector<int> c[10000];
bool v[10000];
void dfs(int n)
{
	v[n]=1;
	for(int x:c[n])
		if(!v[x])
			dfs(x);
}


ll ans;
int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		a[i].in();
		for(int j=0;j<i;++j)
		{
			vec k = a[i]-a[j];
			ld x = atan2((ld)k.y, (ld)k.x);
			if(x > pi || abs(x-pi) < 1e-9) x -= pi;
			if(x < -1e-9) x += pi;
			b.push_back({x, j, i});
		}
	}
	std::sort(b.begin(), b.end());
	//for(auto x:b) printf("%.3f\n", x.x);
	ll t=0, dif=0;
	for(int i=0,j;i<b.size();)
	{
		//if(i+1<b.size())printf("%.3f\n", b[i+1].x-b[i].x);
		for(j=i;j<b.size() && fabs(b[i].x-b[j].x) < 1e-9;++j)
		{
			//printf("%.3f\n", b[i].x-b[j].x);
			c[b[j].i].push_back(b[j].j), c[b[j].j].push_back(b[j].i);
		}
		//printf("%d %d\n", i, j);
		ll n=0;
		for(int k=i;k<j;++k)
			if(!v[b[k].i])
				dfs(b[k].i), ++n;
		t+=n;
		dif += n*(n-1)/2;
		for(;i<j;++i)
			v[b[i].i] = v[b[i].j] = 0, c[b[i].i].clear(), c[b[i].j].clear();
	}
	printf("%lld\n", t*(t-1)/2 - dif);
	return 0;
}