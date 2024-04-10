#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const ldb eps = 1e-9;

inline int sgn(ldb x){ return x < -eps? -1: x > eps? 1: 0;}

struct Vector
{
	ldb x,y;
	Vector(void){}
	Vector(ldb _x,ldb _y): x(_x), y(_y) {}
	inline ldb len(void) const { return sqrtl(x * x + y * y);}
};

Vector operator + (const Vector &p,const Vector &q){ return Vector(p.x + q.x, p.y + q.y);}
Vector operator - (const Vector &p,const Vector &q){ return Vector(p.x - q.x, p.y - q.y);}
Vector operator * (const Vector &p,ldb k){ return Vector(p.x * k, p.y * k);}
Vector operator / (const Vector &p,ldb k){ return Vector(p.x / k, p.y / k);}
ldb cross(const Vector &p,const Vector &q){ return p.x * q.y - p.y * q.x;}
ldb dot(const Vector &p,const Vector &q){ return p.x * q.x + p.y * q.y;}

struct Line
{
	Vector o,v;
	Line(void){}
	Line(const Vector &_o,const Vector &_v): o(_o), v(_v) {}
};
Line make_Line(const Vector &p,const Vector &q){ return Line(p, q - p);}

Vector inter(const Line &a,const Line &b)
{
	return b.o + b.v * (cross(a.o - b.o, a.v) / cross(b.v, a.v));
}
Line midline(const Vector &p,const Vector &q)
{
	Vector o = (p + q) / 2, v = (q - p);
	swap(v.x, v.y); v.x = -v.x;
	return Line(o, v);
}

ldb getres(Vector a,Vector b,Vector c)
{
	auto calc = [&] (Vector o) -> ldb
	{
		return (a - o).len() + (b - o).len() + (c - o).len();
	};
	auto getline = [&] (Vector d,Vector e) -> vector<Line>
	{
		vector<Line> res;
		Line p = midline(a, d);
		res.push_back(make_Line(e, p.o + p.v * sqrtl(3) / 2));
		res.push_back(make_Line(e, p.o - p.v * sqrtl(3) / 2));
		return res;
	};
	
	ldb res = min({calc(a), calc(b), calc(c)});
	auto A = getline(b, c), B = getline(c, b);
	
	for(auto p: A) for(auto q: B)
	{
		if(sgn(cross(p.v, q.v)) == 0) continue;
		res = min(res, calc(inter(p, q)));
	}
	return res;
}

void read(Vector &p)
{
	scanf("%Lf%Lf",&p.x,&p.y);
}

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	Vector a,b,c;
	read(a); read(b); read(c);
	
	auto calc = [&] (const Vector &o)
	{
		return max({getres(o, a, b), getres(o, b, c), getres(o, a, c)});
	};
	
	Vector o;
	{
		Line p = midline(a, b), q = midline(b, c);
		if(sgn(cross(p.v, q.v)) == 0)
		{
			ldb ans = max({(a - b).len(), (b - c).len(), (a - c).len()});
			printf("%.20Lf",ans);
			return 0;
		}
		o = inter(p, q);
	}
	
	mt19937 rnd((unsigned long long)new char ^ time(0));
	auto rndldb = [&] (void) -> ldb
	{
		int x = rnd();
		return (ldb)x / (1ll<<32);
	};
	
	ldb ans = calc(o);
	double T = 1e6;
	static const double pi = 3.1415926535897932384626433832795;
	// cerr << fixed << setprecision(20) << calc(Vector(2.3842, 0.4151)) << endl;
	while (T > 1e-8)
	{
		Vector oo = o;
		double the = rndldb() * 2 * pi;
		oo.x += cos(the) * T;
		oo.y += sin(the) * T;
		ldb nxt = calc(oo);
		if(nxt < ans)
		{
			o = oo;
			ans = nxt;
		}
		T *= 0.99998;
	}
	printf("%.20Lf",ans);
	return 0;
}