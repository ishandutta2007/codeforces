#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 6e3 + 5;
const ldb eps = 1e-9;

inline int sgn(ldb x){ return x<-eps? -1: x>eps? 1: 0;}

struct Data
{
	ldb a,b,c,l,r;
	Data(void){}
	Data(ldb _k): a(1), b(-2 * _k), c(_k * _k) {}
	Data(ldb _a,ldb _b,ldb _c): a(_a), b(_b), c(_c) {}
	Data(ldb _a,ldb _b,ldb _c,ldb _l,ldb _r): a(_a), b(_b), c(_c), l(_l), r(_r) {}
	inline ldb get_y(ldb x) const { return a * x * x + b * x + c;}
	inline pair<ldb,ldb> get_mn(ldb lim) const
	{
		ldb res = -b / (2 * a);
		res = max(res, l); res = min(res, min(lim, r));
		return make_pair(res, get_y(res));
	}
	inline Data shift(ldb k) const
	{
		return Data(a, -2 * a * k + b, k * k * a - b * k + c, l + k, r + k);
	}
	inline void operator += (const Data &oth){ a += oth.a; b += oth.b; c += oth.c;}
	inline void operator -= (const Data &oth){ a -= oth.a; b -= oth.b; c -= oth.c;}
};

int p[MAXN];

inline ostream& operator << (ostream &o,const Data &x)
{
	return o << "(" << x.a << ", " << x.b << ", " << x.c << ") [" << x.l << ", " << x.r << "]";
}

int main(void)
{
	int n,lim,a,b;
	scanf("%d%d%d%d",&n,&lim,&a,&b);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	static int f[MAXN];
	static Data dat[MAXN * 2];
	static ldb g[MAXN];
	int tot = 0;
	for(int i=1; i<=n; ++i)
	{
		if(i == 1)
			dat[1] = Data(p[1]), dat[1].l = 1, dat[1].r = lim, tot = 1;
		else
		{
			int pos = f[i-1];
			for(int j=1; j<pos; ++j) dat[j] = dat[j].shift(a);
			for(int j=tot; j>pos; --j) dat[j+2] = dat[j].shift(b);
			tot += 2;
			
			pair<ldb,ldb> val = dat[pos].get_mn(lim);
			
			ldb tl = val.first + a, tr = val.first + b;
			dat[pos+2] = dat[pos];
			dat[pos+1] = Data(0,0,val.second, tl, tr);
			
			dat[pos] = dat[pos].shift(a); dat[pos].r = tl;
			dat[pos+2] = dat[pos+2].shift(b); dat[pos+2].l = tr;
			
			Data tmp(p[i]);
			for(int j=1; j<=tot; ++j) dat[j] += tmp;
		}
		
		ldb mn = 1e100, mnx;
		for(int j=1; j<=tot && sgn(dat[j].l - lim) <= 0; ++j)
		{
			pair<ldb,ldb> t = dat[j].get_mn(lim);
			if(t.second < mn)
				mn = t.second, f[i] = j, mnx = t.first;
		}
		g[i] = mnx;
	}
	
	static ldb res[MAXN], ans;
	res[n] = g[n];
	ans = dat[f[n]].get_mn(lim).second;
	for(int i=n-1; i>=1; --i)
	{
		ldb vl = res[i+1] - b, vr = res[i+1] - a;
		if(vl <= g[i] && g[i] <= vr)
			res[i] = g[i];
		else res[i] = g[i] < vl? vl: vr;
	}
	
	for(int i=1; i<=n; ++i) printf("%.20lf ",(double)res[i]);
	printf("\n%.20lf",(double)ans);
	return 0;
}