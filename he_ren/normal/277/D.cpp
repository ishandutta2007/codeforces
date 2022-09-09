#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ldb,ldb> pdd;
const int MAXN = 1e3 + 5;
const int MAXM = 1.6e3 + 5;
const ldb eps = 1e-9;

struct Data
{
	int s1, s2, t1, t2;
	ldb p;
	Data(void){}
	inline void read_self(void)
	{
		double _p;
		scanf("%d%d%d%d%lf",&s1,&s2,&t1,&t2,&_p);
		p = _p;
	}
}a[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) a[i].read_self();
	
	sort(a+1,a+n+1, [] (Data x,Data y){
		return x.t2 * x.p * (1 - y.p) < y.t2 * y.p * (1 - x.p);
	});
	
	auto chk = [&] (pdd &x,ldb fir,ldb sec)
	{
		if(fabs(x.first - fir) <= eps)
			x.second = min(x.second, sec);
		else if(x.first < fir)
			x = make_pair(fir, sec);
	};
	
	static pdd f[MAXM];
	for(int i=1; i<=n; ++i)
	{
		int t1 = a[i].t1, t2 = a[i].t2, s1 = a[i].s1, s2 = a[i].s2;
		ldb p = a[i].p;
		for(int j=m; j>=0; --j)
		{
			ldb es = f[j].first, et = f[j].second;
			if(j+t1 <= m)
			{
				chk(f[j+t1],
					es + s1,
					et + t1);
			}
			if(j+t1+t2 <= m)
			{
				chk(f[j+t1+t2],
					es + s1 + s2 * (1-p),
					(et+t1) * p + (j+t1+t2) * (1-p));
			}
		}
	}
	
	pdd ans = make_pair(0,0);
	for(int i=0; i<=m; ++i)
		chk(ans, f[i].first, f[i].second);
	printf("%.20lf %.20lf",(double)ans.first,(double)ans.second);
	return 0;
}