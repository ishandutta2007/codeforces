#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline int rnd(void){ return rand() << 15 | rand();}
inline int rnd(int l,int r){ return rnd() % (r-l+1) + l;}

inline bool isprime(int x)
{
	if(x <= 1) return 0;
	for(int i=2; i*i<=x; ++i)
		if(x%i == 0) return 0;
	return 1;
}

inline int rndprime(void)
{
	int x;
	do x = rnd(1e8, 1e9); while(!isprime(x));
	return x;
}

namespace Hash
{
	int mod1, mod2, base1, base2;
	ll pw1[MAXN], pw2[MAXN];
	void init(void)
	{
		mod1 = rndprime(); mod2 = rndprime();
		base1 = rnd(1e7, mod1 - 1);
		base2 = rnd(1e7, mod2 - 1);
		
		pw1[0] = pw2[0] = 1;
		for(int i=1; i<MAXN; ++i)
			pw1[i] = pw1[i-1] * base1 %mod1,
			pw2[i] = pw2[i-1] * base2 %mod2;
	}
	
	int h1[MAXN], h2[MAXN];
	void build(const char s[],int n)
	{
		h1[0] = h2[0] = 0;
		for(int i=1; i<=n; ++i)
			h1[i] = ((ll)h1[i-1] * base1 + s[i]) %mod1,
			h2[i] = ((ll)h2[i-1] * base2 + s[i]) %mod2;
	}
	inline pii gethash(int l,int r)
	{
		int res1 = (h1[r] - (ll)h1[l-1] * pw1[r-l+1]) %mod1;
		int res2 = (h2[r] - (ll)h2[l-1] * pw2[r-l+1]) %mod2;
		if(res1 < 0) res1 += mod1;
		if(res2 < 0) res2 += mod2;
		return make_pair(res1, res2);
	}
} using Hash::gethash;

char s[MAXN];
int res[MAXN];

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	int n;
	scanf("%d%s",&n,s+1);
	
	Hash::init();
	Hash::build(s, n);
	
	auto chk = [&] (int k,int len)
	{
		if(len < 0) return true;
		int l = k, r = n - k + 1;
		if(len >= r - l + 1) return false;
		return gethash(l, l+len-1) == gethash(r-len+1, r);
	};
	
	int cur = n % 2? n: n + 1;
	for(int i=(n+1)/2; i>=1; --i)
	{
		cur += 2;
		while(!chk(i, cur)) cur -= 2;
		res[i] = cur;
	}
	
	for(int i=1; i<=(n+1)/2; ++i) printf("%d ",res[i]);
	return 0;
}