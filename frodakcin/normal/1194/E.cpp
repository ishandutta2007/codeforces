#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
 
using namespace std;
 
using ll = long long;
#define tl(X) static_cast<ll>(X)
 
const int MN = 5e3 + 100;
int N;
struct V
{
public:
	int x;
	int y1, y2;
	bool operator < (const V& o) const {return x < o.x;}
};
vector<V> v;
struct H
{
public:
	int x, y;
	bool a;
	bool operator < (const H& o) const {return x < o.x||(!(o.x < x) && a < o.a);}
};
vector<H> h;
 
const int MV = 1e4 + 1000;
int bit[MV];
bool ex[MV];
void upd(int x, int v)
{
	for(++x;x < MV;x+=-x&x) bit[x]+=v;
}
int cnt(int x)
{
	int r = 0;
	for(++x;x;x-=-x&x) r += bit[x];
	return r;
}
 
ll ans;
int c2(int x) {return (x*(x-1)>>1);}
const int dif[2] = {-1,1};
 
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, a, b, c, d;i < N;i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(c<a) swap(a,c);if(d<b) swap(b,d);
		b+=5010, d+=5010;
		if(a==c)
			v.push_back({a,b,d});
		else if(b==d)
			h.push_back({a,b,1}), h.push_back({c+1,b,0});
		else
			assert(0);
	}
	sort(v.begin(),v.end());
	sort(h.begin(),h.end());
	for(int i = 0, k;i < v.size();i++)
	{
		for(k=0;k<h.size() && h[k].x <= v[i].x;k++)
			if(v[i].y1 <= h[k].y && h[k].y <= v[i].y2)
				ex[h[k].y] = h[k].a, upd(h[k].y, dif[h[k].a]);
		for(int j = i+1;j < v.size();j++)
		{
			for(;k<h.size() && h[k].x <= v[j].x;k++)
				if(!h[k].a && ex[h[k].y])
					upd(h[k].y, -1), ex[h[k].y] = 0;
			ans += c2(cnt(v[j].y2)-cnt(v[j].y1-1));
		}
		for(;k < h.size();k++)
			if(ex[h[k].y])
				upd(h[k].y, -1), ex[h[k].y] = 0;
	}
	printf("%lld\n", ans);
	return 0;
}