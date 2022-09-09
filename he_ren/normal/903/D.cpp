#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int Base = 1e9;

inline ll Abs(ll x){ return x<0? -x: x;}

struct Data
{
	bool f;
	ll p,q;
	Data(){ p=q=f=0;}
	Data(ll pp,ll qq){ p=pp; q=qq;}
	Data(ll x){ p=x/Base; q=x%Base;}
	
	inline void add(const ll y)
	{
		bool ff=(y<0);
		if(ff==f) *this+=Abs(y);
		else *this-=Abs(y);
	}
	inline bool operator < (const Data y){ return p==y.p? q<y.q: p<y.p;}
	inline void operator += (const ll y)
	{
		q+=y;
		p+=q/Base; q%=Base;
	}
	inline void operator -= (const ll y)
	{
		Data b(y);
		if(*this < b)
		{
			swap(p,b.p); swap(q,b.q);
			f=!f;
		}
		p-=b.p; q-=b.q;
		if(q<0) q+=Base, --p;
		if(!p && !q) f=0;
	}
	inline void print(void)
	{
		if(f) putchar('-');
		int qq=q;
		if(p) cout<<p, printf("%09d",qq);
		else printf("%d",qq);
	}
}ans;

int a[MAXN];
ll s[MAXN];
map<int,int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		s[i] = s[i-1]+a[i];
	
	for(int i=1; i<=n; ++i)
	{
		ll sum = s[i-1];
		int cnt = i-1;
		for(int j=-1; j<=1; ++j)
		{
			if(t.find(a[i]+j) == t.end()) continue;
			int tcnt = t[a[i]+j];
			cnt -= tcnt;
			sum -= (ll)tcnt*(a[i]+j);
		}
		
		ans.add((ll)cnt*a[i] - sum);
		++t[a[i]];
	}
	ans.print();
	return 0;
}