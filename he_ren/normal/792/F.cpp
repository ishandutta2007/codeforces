#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const ldb eps = 1e-12;

inline int sgn(ldb x){ return x<-eps? -1: x>eps? 1: 0;}

struct Line
{
	ll a, b, c; // ax + by = c
	Line(void){}
	Line(ll _a,ll _b,ll _c): a(_a), b(_b), c(_c) {}
};

ll cmp(const Line &A,const Line &B)
{
	return (- A.a * B.b) - (- A.b * B.a);
}
bool operator < (const Line &A,const Line &B){ return cmp(A, B) < 0;}
bool operator == (const Line &A,const Line &B){ return cmp(A, B) == 0;}

ldb interx(const Line &A,const Line &B)
{
	return ldb(A.c * B.b - A.b * B.c) / (A.a * B.b - A.b * B.a);
}
ldb intery(const Line &A,const Line &B)
{
	return ldb(A.a * B.c - A.c * B.a) / (A.a * B.b - A.b * B.a);
}
bool chk(const Line &A,const Line &B,const Line &C)
{
	return interx(A,B) < interx(B,C);
}

int main(void)
{
	int Q; ll m;
	scanf("%d%lld",&Q,&m);
	
	set<Line> h;
	h.emplace(1, 0, 0);
	h.emplace(0, 1, 0);
	
	auto insert = [&] (Line p)
	{
		auto it = h.lower_bound(p);
		if(*it == p)
		{
			if(it -> c >= p.c) return;
			h.erase(it++);
		}
		if(!chk(*prev(it), p, *it)) return;
		
		while(next(it) != h.end() && !chk(p, *it, *next(it)))
			h.erase(it++);
		--it;
		while(it != h.begin() && !chk(*prev(it), *it, p))
			h.erase(it--);
		
		h.emplace_hint(it, p);
	};
	auto query = [&] (Line p) -> ldb
	{
		auto it = h.lower_bound(p);
		ldb x = interx(*prev(it), *it);
		ldb y = intery(*prev(it), *it);
		return p.a * x + p.b * y;
	};
	
	int lstyes = 0;
	for(int rn=1; rn<=Q; ++rn)
	{
		int type, qa, qb;
		scanf("%d%d%d",&type,&qa,&qb);
		
		const int base = 1e6;
		qa = (qa + lstyes) % base + 1;
		qb = (qb + lstyes) % base + 1;
		
		if(type == 1)
			insert(Line(1, qb, qa));
		else
		{
			ldb res = query(Line(qa, m, 0));
			if(sgn(res - qb) >= 0)
				printf("YES\n"), lstyes = rn;
			else
				printf("NO\n");
		}
	}
	return 0;
}