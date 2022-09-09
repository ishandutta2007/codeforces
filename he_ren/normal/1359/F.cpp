#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 2.5e4 + 5;
const ldb eps = 1e-8;

mt19937 rnd((unsigned long long)new char ^ time(0));

struct Vector
{
	ldb x,y;
	Vector(void){}
	Vector(ldb _x,ldb _y): x(_x), y(_y) {}
	void read_self(void)
	{
		int _x,_y;
		scanf("%d%d",&_x,&_y);
		x = _x; y = _y;
	}
	ldb len(void) const
	{
		return sqrtl(x * x + y * y);
	}
};
typedef Vector Point;

Vector operator + (const Vector &p,const Vector &q){ return Vector(p.x + q.x, p.y + q.y);}
Vector operator - (const Vector &p,const Vector &q){ return Vector(p.x - q.x, p.y - q.y);}
Vector operator * (const Vector &p,ldb k){ return Vector(p.x * k, p.y * k);}

struct Line
{
	ldb k,b;
	Line(void){}
	Line(ldb _k,ldb _b): k(_k), b(_b) {}
	Line(Point p1,Point p2)
	{
		k = (p1.y - p2.y) / (p1.x - p2.x);
		b = p1.y - k * p1.x;
	}
	ldb get(ldb x) const { return k * x + b;}
};

int n;
Vector pt[MAXN], dir[MAXN];
int s[MAXN];

ldb fl[MAXN], fr[MAXN];
Line f[MAXN];

struct Cmp
{
	static ldb x;
	bool operator () (int i,int j) const
	{
		ldb yi = f[i].get(x), yj = f[j].get(x);
		return yi != yj? yi < yj: i < j;
	}
}cmp;
ldb Cmp::x;

bool chk(ldb T)
{
	vector< pair<ldb,int> > eff;
	for(int i=1; i<=n; ++i)
	{
		Point pl = pt[i], pr = pt[i] + dir[i] * (s[i] * T);
		if(pl.x > pr.x) swap(pl, pr);
		fl[i] = pl.x; fr[i] = pr.x;
		f[i] = Line(pl, pr);
		eff.emplace_back(fl[i], i);
		eff.emplace_back(fr[i], -i);
	}
	sort(eff.begin(), eff.end());
	
	auto isvalid = [&] (int i,int j) -> bool
	{
		ldb l = max(fl[i], fl[j]), r = min(fr[i], fr[j]);
		if(l > r) return 1;
		if(f[i].get(l) > f[j].get(l)) swap(i, j);
		if(f[i].get(l) >= f[j].get(l) - eps) return 0;
		if(f[i].get(r) >= f[j].get(r) - eps) return 0;
		return 1;
	};
	
	set<int,Cmp> t;
	static decltype(t.begin()) mem[MAXN];
	
	for(auto e: eff)
	{
		Cmp::x = e.first;
		int i = e.second;
		if(i < 0)
		{
			auto it = mem[-i];
			t.erase(it++);
			if(it != t.begin() && it != t.end() && !isvalid(*prev(it), *it))
				return 1;
		}
		else
		{
			auto it = mem[i] = t.insert(i).first;
			if(it != t.begin() && !isvalid(*prev(it), i))
				return 1;
			if(next(it) != t.end() && !isvalid(i, *next(it)))
				return 1;
		}
	}
	return 0;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		pt[i].read_self();
		dir[i].read_self();
		scanf("%d",&s[i]);
		dir[i] = dir[i] * (1 / dir[i].len());
	}
	
	{
		ldb tcos = (ldb)(int)rnd() / 0x7fffffff;
		ldb tsin = sqrtl(max((ldb)0, 1 - tcos * tcos));
		if(rnd() % 2) tsin = -tsin;
		auto random_rotate = [&] (Vector p)
		{
			return Vector(
				p.x * tcos - p.y * tsin,
				p.x * tsin + p.y * tcos
			);
		};
		for(int i=1; i<=n; ++i)
		{
			pt[i] = random_rotate(pt[i]);
			dir[i] = random_rotate(dir[i]);
		}
	}
	
	ldb l = 0, r = 1e10;
	if(!chk(r))
	{
		printf("No show :(");
		return 0;
	}
	for(int T=1; T<=80; ++T)
	{
		ldb mid = (l+r)/2;
		if(chk(mid)) r=mid;
		else l=mid;
	}
	
	printf("%.20lf",(double)l);
	return 0;
}