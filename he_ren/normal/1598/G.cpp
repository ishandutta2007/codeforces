// hack me, please
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 2e5 + 5;

inline ll rnd(void){ return ((ll)rand()<<31) | rand();}

inline bool is_prime(int x)
{
	for(int i=2; i*i<=x; ++i)
		if(x%i == 0) return 0;
	return 1;
}

struct Hash
{
	int mod;
	ll pw10[MAXN], h[MAXN];
	void build(char s[],int n)
	{
		do
			mod = 1e8 + rnd() % (int)9e8;
		while(!is_prime(mod));
		
		pw10[0] = 1;
		for(int i=1; i<MAXN; ++i) pw10[i] = pw10[i-1] * 10 %mod;
		h[0] = 0;
		for(int i=1; i<=n; ++i) h[i] = (h[i-1] * 10 + s[i] - '0') %mod;
	}
	inline int get(int l,int r)
	{
		int res = (h[r] - h[l-1] * pw10[r-l+1]) %mod;
		return res < 0? res + mod: res;
	}
	inline int get(char s[],int n)
	{
		ll res = 0;
		for(int i=1; i<=n; ++i)
			res = (res * 10 + s[i] - '0') %mod;
		return res;
	}
	inline int get(int l1,int r1,int l2,int r2)
	{
		int res = get(l1, r1) + get(l2, r2);
		return res >= mod? res - mod: res;
	}
};

namespace Hash5
{
	Hash h1, h2, h3, h4, h5, h6, h7, h8, h9, h10;
	typedef array<int,10> Data;
	#define func(f,...) h1.f(__VA_ARGS__), h2.f(__VA_ARGS__), h3.f(__VA_ARGS__), h4.f(__VA_ARGS__), h5.f(__VA_ARGS__), h6.f(__VA_ARGS__), h7.f(__VA_ARGS__), h8.f(__VA_ARGS__), h9.f(__VA_ARGS__), h10.f(__VA_ARGS__)
	#define ret_get(...) return { func(get,__VA_ARGS__)};
	inline void build(char s[],int n){ func(build, s, n);}
	inline Data get(char s[],int n){ ret_get(s,n);}
	inline Data get(int l,int r){ ret_get(l,r);}
	inline Data get(int l1,int r1,int l2,int r2){ ret_get(l1,r1,l2,r2);}
	#undef func
	#undef ret_get
} using namespace Hash5;

vector<int> get_z(const string &s)
{
	int n = (int)s.size();
	vector<int> z(n);
	z[0] = n;
	for(int i=1,l=0,r=0; i<n; ++i)
	{
		z[i] = i<r? min(z[i-l], r-i): 0;
		while(i+z[i]<n && s[i+z[i]] == s[z[i]]) ++z[i];
		if(i+z[i] > r) l = i, r = i + z[i];
	}
	return z;
}

int n,m;
char s[MAXN], t[MAXM];
int len9[MAXN], lcp[MAXN];
int len0[MAXM];

Data dat_t;
inline void chk(int l1,int r1,int l2,int r2)
{
	if(get(l1,r1,l2,r2) == dat_t)
	{
		if(l1 > l2) swap(l1, l2), swap(r1, r2);
		printf("%d %d\n%d %d",l1,r1,l2,r2), exit(0);
	}
}

vector<int> get_len(int l,int r)
{
	int pos, dif, post;
	if(r - l + 1 < m) pos = l - 1, dif = t[1] - '0', post = 1;
	else
	{
		if(lcp[l] >= m) return vector<int>{};
		pos = l + lcp[l];
		post = 1 + lcp[l];
		dif = (int)t[post] - (int)s[pos];
	}
	if(dif < 0) return vector<int>{};
	
	vector<int> res(1, r - pos + 1);
	if(pos == r || dif != 1) return res;
	
	int len = min(len9[pos+1], r-pos);
	if(pos + len + 1 <= r)
		res.push_back(r - (pos + len));
	
	res.push_back(r - (pos + len) + 1);
	res.push_back(m - min(post + len0[post + 1] + 1, m) + 1);
	return res;
}

inline void chk_len(int l,int r,int k)
{
	if(k < 1) return;
	if(r + k <= n) chk(l, r, r+1, r+k);
	if(l - k >= 1) chk(l, r, l-k, l-1);
}

int main(void)
{
	srand((unsigned long long)new char ^ time(0));
	
	scanf("%s%s",s+1,t+1);
	n = strlen(s+1); m = strlen(t+1);
	reverse(t+1,t+m+1);
	while(t[m] == '0') t[m--] = 0;
	reverse(t+1,t+m+1);
	
	build(s,n);
	dat_t = get(t,m);
	
	vector<int> z = get_z(string(t+1,t+m+1) + string(s+1,s+n+1));
	for(int i=1; i<=n; ++i)
		lcp[i] = min(z[i + m - 1], m);
	
	for(int i=n; i>=1; --i)
		len9[i] = s[i] == '9'? len9[i+1] + 1: 0;
	for(int i=m; i>=1; --i)
		len0[i] = t[i] == '0'? len0[i+1] + 1: 0;
	
	for(int i=m-1; i<=m; ++i) if(i >= 1)
		for(int l=1; l+i-1<=n; ++l)
		{
			int r = l + i - 1;
			vector<int> vec = get_len(l, r);
			for(int x: vec) chk_len(l, r, x);
		}
	return 0;
}