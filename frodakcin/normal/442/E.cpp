#include <cstdio>
#include <ctime>
#include <cmath>
#include <random>
#include <algorithm>

std::mt19937 rng;

using ll = long long;
using ld = long double;
const int MN = 1e3+10;
const ld PI = acos((ld)-1);
const ld MXV = log(1e6*sqrt((ld)2));

int N, W, H;
struct vec
{
public:
	int x, y;
	void in(){scanf("%d%d", &x, &y);}
	ld ang() {return atan2((ld)y, (ld)x);}
	ld mag() {return hypot((ld)x, (ld)y);}
	bool operator == (vec o) const {return x==o.x&&y==o.y;}
	bool operator != (vec o) const {return x!=o.x||y!=o.y;}
	vec& operator -= (vec b) {return x-=b.x, y-=b.y, *this;}

	friend vec operator - (vec a, vec b) {return a-=b;}
} a[MN];
struct event
{
public:
	ld t;
	bool a;
	int val(){return a?1:-1;}
	bool operator < (event o) const {return t < o.t;}
};
int num;
std::vector<event> e;
void addb(ld i, ld f)
{
	if(i<0)i+=2*PI, f+=2*PI;
	if(i>2*PI)i-=2*PI, f-=2*PI;
	//printf("%.3Lg -> %.3Lg\n", i*180/PI, f*180/PI);

	if(f<2*PI)
		e.push_back({i, 1}), e.push_back({f, 0});
	else
		++num, e.push_back({i, 1}), e.push_back({f-2*PI, 0});
}
bool test(int n, ld d)
{
	if(a[n].y<d)
	{
		ld delta=acos((a[n].y)/d);
		addb(3*PI/2-delta, 3*PI/2+delta);
		addb(3*PI/2-delta, 3*PI/2+delta);
	}
	if(H-a[n].y<d)
	{
		ld delta=acos((H-a[n].y)/d);
		addb(PI/2-delta, PI/2+delta);
		addb(PI/2-delta, PI/2+delta);
	}
	if(a[n].x<d)
	{
		ld delta=acos((a[n].x)/d);
		addb(PI-delta, PI+delta);
		addb(PI-delta, PI+delta);
	}
	if(W-a[n].x<d)
	{
		ld delta=acos((W-a[n].x)/d);
		addb(-delta, delta);
		addb(-delta, delta);
	}
	for(int i=0;i<N;++i)
		if(a[i]!=a[n])
		{
			vec x=a[i]-a[n];
			ld r=x.mag()/2;
			if(d<r)
				continue;
			ld m=x.ang();
			ld delta=acos(r/d);
			addb(m-delta, m+delta);
		}
	std::sort(e.begin(), e.end());
	bool good = num<=1;
	if(!good)
		for(auto x:e)
			if((num += x.val()) <= 1)
			{
				good=1;
				break;
			}
	e.clear();
	num=0;
	return good;
}
ld ans=-22;
int main(void)
{
	rng = std::mt19937(time(0));
	scanf("%d%d%d", &W, &H, &N);
	for(int i=0;i<N;++i)
		a[i].in();
	std::shuffle(a, a+N, rng);
	for(int i=0;i<N;++i)
		if(test(i, exp(ans)))
		{
			ld l=ans,r=MXV,m;
			for(int j=0;j<50;++j)
			{
				m=(l+r)/2;
				if(test(i, exp(m)))
					l=m;
				else
					r=m;
			}
			ans=r;
		}
	printf("%.15Lg\n", exp(ans));
	return 0;
}