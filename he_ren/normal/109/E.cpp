#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 5e17;

inline int f(ll x)
{
	ll res = 0;
	for(; x; x/=10)
		if(x%10 == 4 || x%10 == 7) ++res;
	return res;
}

ll get_fir(ll l,int x)
{
	if(x<0) return linf;
	
	static map<ll,ll> t[20];
	if(t[x].find(l) != t[x].end()) return t[x][l];
	if(l <= 3)
	{
		if(!x) return l;
		ll res = 0;
		for(int i=1; i<=x; ++i) res = res * 10 + 4;
		return t[x][l] = res;
	}
	
	ll res = linf;
	for(int i=0; i<=9; ++i)
		res = min(res, get_fir(l/10 + (i < l%10), x - f(i)) * 10 + i);
	return t[x][l] = res;
}

ll get_fir(ll l,int x,int y)
{
	ll res = linf;
	for(ll pw10=1; pw10 < res; pw10*=10)
	{
		ll cur = linf;
		for(int i=0; i<9; ++i)
			if(f(i+1) - f(i) == y - x)
				cur = min(cur, get_fir(l/10 + (i < (l%10)), x - f(i)) * 10 + i);
		
		if(cur <= (res - (pw10 - 1)) / pw10)
			res = cur * pw10 + (pw10 - 1);
		if(!l) break;
		l /= 10;
	}
	return res;
}

ll get_res(ll l,ll r)
{
	if(l/10 + 2 <= r/10) return 10 * get_res(l/10, r/10) + l % 10;
	
	ll res = linf;
	for(int i=0; i<=9; ++i)
	{
		int j = i + (r-l);
		if(j >= 20) break;
		int x = f(l) - f(i), y = f(r) - f(j%10);
		if(x<0 || y<0) continue;
		
		bool ok = 1;
		for(int k=i; k<=j; ++k)
			if(f(l + (k-i)) != (k<10? x + f(k): y + f(k-10)))
			{
				ok = 0;
				break;
			}
		if(!ok) continue;
		
		ll mn = (l - i + 10) / 10;
		if(j < 10)
			res = min(res, get_fir(mn,x) * 10 + i);
		else
			res = min(res, get_fir(mn,x,y) * 10 + i);
	}
	return res;
}

int main(void)
{
	int a,l;
	scanf("%d%d",&a,&l);
	printf("%lld",get_res(a, a+l-1));
	return 0;
}