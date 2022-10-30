#include<iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>
#include <functional>
#define mp(x, y, z) pair<long long, long long> z=make_pair(x, y)
#define pb(x, y) x.push_back(y)
#define ff(x)  if(x>0)
#define cn(x) cin>>x
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pr;
typedef vector <long long>  vl;
typedef int nt;
#pragma comment(linker, "/STACK:2000000")
// *
ll fact[100005], ofact[100005], p = 998244353, root, sz = 262144, obroot, logs = 18, obrt[100005];
vector<ll> rev_pow, orev_pow, pow1, opow, revmas;
ll bp(ll a, ll b)
{
	{
		if (b == 0)
		{
			return 1;
		}
		else
			if (b % 2 == 0)
			{
			ll aq = bp(a, b / 2);
			return (aq*aq) % p;
			}
			else
			{
				ll aq = bp(a, b - 1);
				return (aq*a) % p;
			}
	}
}
ll obr(ll x)
{
	return bp(x, p - 2);
}
void mlt1(vector<ll> &v1, vector<ll> &v2, vector<ll> &v3)
{
	for (nt j = 0; j < sz; j++)
	{
		v3[j] = v1[j] * v2[j];
		v3[j] %= p;
	}
}
ll rev(ll j)
{
	ll y = 0, cur = j;
	for (nt h = 0; h < logs; h++)
	{
		ll x = cur % 2;
		y += (x << logs - 1 - h);
		cur /= 2;
	}
	return y;
}
void b_reverse(vector<ll>&v1)
{
	vector<ll>used;
	used.resize(sz);
	for (nt j = 0; j < sz; j++)
	{
		ll x;
		ff(1 - used[j])
		{
			x = v1[j];
			v1[j] = v1[revmas[j]];
			v1[rev(j)] = x;
			used[j] = 1;
			used[rev(j)] = 1;
		}
	}
}
ll transf(ll g, ll j)
{
	ll h = g - ((g >> j) << j);
	return h;
}
void fft(vector<ll>&v1)
{
	vector<ll> v2;
	v2.resize(sz);
	for (nt j = 0; j < logs; j++)
	{
		ff(1 - j % 2)
		{
			ll blc = 1 << (j + 1);
			for (nt h = 0; h < sz / blc; h++)
			{
				for (nt g = 0; g < blc; g++)
				{
					v2[h *blc + g] = v1[h *blc + (g>>1)] + v1[h *blc + (g>>1) + (blc>>1)] * rev_pow[transf(g, j + 1)];
					v2[h *blc + g] %= p;
				}
			}
		}
		ff(j % 2)
		{
			ll blc = 1 << (j + 1);
			for (nt h = 0; h < sz / blc; h++)
			{
				for (nt g = 0; g < blc; g++)
				{
					v1[h *blc + g] = v2[h *blc + (g>>1)] + v2[h *blc + (g>>1) + (blc>>1)] * rev_pow[transf(g, j + 1)];
					v1[h *blc + g] %= p;
				}
			}
		}
	}
}
void dft(vector<ll>&v1)
{
	vector<ll> v2;
	ll osz = obr(sz);
	v2.resize(sz);
	for (nt j = 0; j < logs; j++)
	{
		ff(1 - j % 2)
		{
			ll blc = 1 << (j + 1);
			for (nt h = 0; h < sz / blc; h++)
			{
				for (nt g = 0; g < blc; g++)
				{
					v2[h *blc + g] = v1[h *blc + (g>>1)] + v1[h *blc + (g>>1) + (blc>>1)] * orev_pow[transf(g, j + 1)];
					v2[h *blc + g] %= p;
				}
			}
		}
		ff(j % 2)
		{
			ll blc = 1 << (j + 1);
			for (nt h = 0; h < sz / blc; h++)
			{
				for (nt g = 0; g < blc; g++)
				{
					v1[h *blc + g] = v2[h *blc + (g>>1)] + v2[h *blc + (g>>1)  + (blc>>1)] * orev_pow[transf(g, j + 1)];
					v1[h *blc + g] %= p;
				}
			}
		}
	}
	for (nt j = 0; j < sz; j++)
	{
		v1[j] *= osz;
		v1[j] %= p;
	}
}
void mlt(vector<ll> &v1, vector<ll> &v2, vector<ll> &v3, ll oo)
{
	v1.resize(sz);
	v2.resize(sz);
	v3.resize(sz);
	b_reverse(v1);
	b_reverse(v2);
	fft(v1);
	fft(v2);
	mlt1(v1, v2, v3);
	dft(v3);
	b_reverse(v3);
	v3.resize(oo);
}
void umn(vector<ll>&v)
{
	nt x = v.size();
	for (nt j = 0; j < x; j++)
	{
		v[j] *= fact[j];
		v[j] %= p;
	}
}
void umn1(vector<ll>&v)
{
	nt x = v.size();
	for (nt j = 0; j < x; j++)
	{
		v[j] *= ofact[j];
		v[j] %= p;
	}
}

void mn(vector<ll>&v)
{
	nt x = v.size();
	for (nt j = 0; j < x; j++)
	{
		ff(j % 2)
		{
			v[j] = p-v[j];
		}
	}
}
void encode(vector<ll>&v)
{
	vector<ll> v1 = v, v2, v3;
	umn(v1);
	reverse(v1.begin(), v1.end());
	nt x = v.size();
	v2.resize(x);
	for (nt j = 0; j < x; j++)
	{
		v2[j]=ofact[j];
	}
	mlt(v1, v2, v3, x);
	reverse(v3.begin(), v3.end());
	umn1(v3);
	for (nt j = 0; j < x; j++)
	{
		v[j] = v3[j];
	}
}
void decode(vector<ll>&v)
{
	vector<ll> v1 = v, v2, v3;
	umn(v1);
	mn(v1);
	reverse(v1.begin(), v1.end());
	nt x = v.size();
	v2.resize(x);
	for (nt j = 0; j < x; j++)
	{
		v2[j]=ofact[j];
	}
	mlt(v1, v2, v3, x);
	reverse(v3.begin(), v3.end());
	umn1(v3);
	mn(v3);
	for (nt j = 0; j < x; j++)
	{
		v[j] = v3[j];
	}
}
void oper(vector<ll>&v, ll m)
{
	ll n = v.size(), m1 = m % (p - 1);
	for (nt j = 0; j < n; j++)
	{
		ll x = bp(j + 1, p-1-m1);
		v[j] *= x;
		v[j] %= p;
	}
}
void calc()
{
	fact[0] = 1;
	ofact[0] = 1;
	for (nt j = 1; j < 100001; j++)
	{
		ff(2 - j)
		{
			obrt[1] = 1;
		}
		ff(j - 1)
		{
			obrt[j] = (p - (p / j) * obrt[p%j] % p) % p;
		}
		fact[j] = fact[j - 1] * j;
		fact[j] %= p;
		ofact[j] = ofact[j - 1] * obrt[j];
		ofact[j] %= p;
	}
}
void clc()
{
	revmas.resize(sz);
	vector<ll> rm;
	rm.resize(sz);
	for (nt j = 0; j < logs; j++)
	{
		ff(1 - j % 2)
		{
			for (nt h = 0; h < (1 << (j + 1)); h++)
			{
				rm[h] = revmas[h / 2] + ((h % 2) << j);
			}
		}
		ff(j % 2)
		{
			for (nt h = 0; h < (1 << (j + 1)); h++)
			{
				revmas[h] = rm[h / 2] + ((h % 2) << j);
			}
		}
	}
}
void pow_calcs()
{
	rev_pow.resize(sz);
	orev_pow.resize(sz);
	pow1.resize(sz);
	opow.resize(sz);
	pow1[0] = 1;
	opow[0] = 1;
	for (nt j = 1; j < sz; j++)
	{
		pow1[j] = pow1[j - 1] * root;
		pow1[j] %= p;
		opow[j] = opow[j - 1] * obroot;
		opow[j] %= p;
	}
	for (nt j = 0; j < sz; j++)
	{
		rev_pow[j] = pow1[revmas[j]];
		orev_pow[j] = opow[revmas[j]];
	}
}
nt main()
{
	root = bp(5, 32 * 119);
	obroot = obr(root);
	clc();
	pow_calcs();
	ll n, m;
	vector<ll> v;
	cn(n);
	cn(m);
	for (nt j = 0; j < n + 1; j++)
	{
		ll x;
		cn(x);
		v.push_back(x);
	}
	calc();
	encode(v);
	oper(v, m);
	decode(v);
	for (nt j = 0; j < n + 1; j++)
	{
		cout << v[j] % p << ' ';
	}
	return 0;
}