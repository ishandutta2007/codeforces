#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

typedef long long ll;
typedef set<pair<int,int> >::iterator Sit;

const int MAXN = 200005;
const ll MOD = 998244353;

int n,q,t,x,y;

ll v;
ll mul[MAXN << 2];
ll add[MAXN << 2];
ll sum[MAXN << 2];

pair<int,int> p;
set<pair<int,int> > S[MAXN];

void tag1(int o,ll val)
{
	(sum[o] *= val) %= MOD;
	(mul[o] *= val) %= MOD;
	(add[o] *= val) %= MOD;
}

void tag2(int o,int l,int r,ll val)
{
	(sum[o] += val * (r - l + 1)) %= MOD;
	(add[o] += val) %= MOD;
}

void pushdown(int o,int l,int r)
{
	int mid = (l + r) >> 1;
	if (mul[o] != 1)
	{
		tag1(o << 1,mul[o]);
		tag1(o << 1 | 1,mul[o]);
		mul[o] = 1;
	}
	if (add[o])
	{
		tag2(o << 1,l,mid,add[o]);
		tag2(o << 1 | 1,mid + 1,r,add[o]);
		add[o] = 0;
	}
}

void Mul(int o,int l,int r,int x,int y)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
	//	cout << "Mul:" << l << ',' << r << endl;
		tag1(o,2);
		return;
	}
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	if (mid >= x)
		Mul(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		Mul(o << 1 | 1,mid + 1,r,x,y);
	sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % MOD;
}

void Add(int o,int l,int r,int x,int y)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
	//	cout << "Add:" << l << ',' << r << "++" << endl;
		tag2(o,l,r,1);
		return;
	}
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	if (mid >= x)
		Add(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		Add(o << 1 | 1,mid + 1,r,x,y);
	sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % MOD;
}

ll query(int o,int l,int r,int x,int y)
{
//	cout << "query:" << x << ',' << y << endl;
	if (l >= x && r <= y)
		return sum[o];
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	ll ret = 0;
	if (mid >= x)
		(ret += query(o << 1,l,mid,x,y)) %= MOD;
	if (mid + 1 <= y)
		(ret += query(o << 1 | 1,mid + 1,r,x,y)) %= MOD;
	return ret;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);
	for (int i = 0;i < (MAXN << 2);i++)
		mul[i] = 1;
	cin >> n >> q;
	for (int i = 1;i <= q;i++)
	{
	//	cout << endl;
		cin >> t;
		if (t == 1)
		{
			cin >> p.first >> p.second >> v;
			if (S[v].empty())
			{
				Add(1,1,n,p.first,p.second);
				S[v].insert(p);
				continue;
			}
			Sit it = S[v].lower_bound(p);
			if (it != S[v].begin())
			{
				it--;
				if ((*it).second < p.first)
					it++;
				if (it == S[v].end())
				{
					S[v].insert(p);
					Add(1,1,n,p.first,p.second);
					continue;
				}
			}
			if ((*it).first <= p.first && (*it).second >= p.second)
			{
				Mul(1,1,n,p.first,p.second);
				continue;
			}
			if ((*it).first > p.second)
			{
				Add(1,1,n,p.first,p.second);
				S[v].insert(p);
				continue;
			}
			int ll = p.first,rr = p.second;
			if ((*it).first > p.first)
				Add(1,1,n,p.first,(*it).first - 1);
			while (it != S[v].end() && (*it).first <= p.second)
			{
				ll = min(ll,(*it).first);
				rr = max(rr,(*it).second);
				if ((*it).second > p.second)
					Mul(1,1,n,(*it).first,p.second);
				else
				{
					Mul(1,1,n,max(p.first,(*it).first),(*it).second);
					int pre = (*it).second + 1,next = p.second;
					it++;
					if (it != S[v].end())
						next = min(next,(*it).first - 1);
					Add(1,1,n,pre,next);
					it--;
				}
				S[v].erase(it++);
			}
			S[v].insert(make_pair(ll,rr));
		}
		else
		{
			cin >> p.first >> p.second;
			cout << query(1,1,n,p.first,p.second) << endl;
		}
	}
	return 0;
}