#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n,m,top;

pair<int,int> c[MAXN];
pair<int,int> stk[MAXN];

ll MUL[MAXN << 2],MOD;
ll H[MAXN << 2];
ll mul[4] = {5767169,23068673,167772161,1000000007};
ll prime[4] = {7340033,104857601,469762049,1004535809};

vector<ll> ret1,ret2;

ll area(const pair<int,int> &a,const pair<int,int> &b,const pair<int,int> &c)
{
	return (ll)a.first * (b.second - c.second) + (ll)b.first * (c.second - a.second) + (ll)c.first * (a.second - b.second);
}

ll dist(const pair<int,int> &a,const pair<int,int> &b)
{
	return (ll)(a.first - b.first) * (a.first - b.first) + (ll)(a.second - b.second) * (a.second - b.second);
}

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if (area(a,c[1],b) == 0)
		return dist(a,c[1]) < dist(b,c[1]);
	return area(a,c[1],b) < 0;
}

void gethull(vector<ll> &p,int l)
{
	for (int i = 2;i <= l;i++)
		if (c[i].second < c[1].second || (c[i].second == c[1].second && c[i].first < c[1].first))
			swap(c[1],c[i]);
	sort(c + 2,c + l + 1,cmp);
	top = 0;
	stk[++top] = c[1];
	stk[++top] = c[2];
	for (int i = 3;i <= l;i++)
	{
		while (top >= 2 && area(stk[top - 1],stk[top],c[i]) <= 0)
			top--;
		stk[++top] = c[i];
	}
	for (int i = 1;i <= top;i++)
	{
		p.push_back(dist(stk[i],stk[i % top + 1]));
		p.push_back(dist(stk[i % top + 1],stk[(i + 1) % top + 1]));
		p.push_back(dist(stk[i],stk[(i + 1) % top + 1]));
	}
}

ll getHash(int l,int r)
{
	return ((H[r] - H[l - 1] * MUL[r - l + 1]) % MOD + MOD) % MOD;
}

bool ok()
{
	ll HH = 0;
	for (int i = 1;i <= ret1.size();i++)
		HH = (HH * MUL[1] + ret1[i - 1]) % MOD;
	for (int i = 1;i <= ret2.size();i++)
		H[i] = (H[i - 1] * MUL[1] + ret2[i - 1]) % MOD;
	for (int i = 1;i <= ret2.size();i++)
	{
		ll HH_ = (getHash(i,ret2.size()) * MUL[i - 1] + getHash(1,i - 1)) % MOD;
		if (HH_ == HH)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> c[i].first >> c[i].second;
	gethull(ret1,n);
	for (int i = 1;i <= m;i++)
		cin >> c[i].first >> c[i].second;
	gethull(ret2,m);
	if (ret1.size() != ret2.size())
	{
		cout << "NO" << endl;
		return 0;
	}
	MUL[0] = 1;
	for (int i = 0;i < 4;i++)
	{
		MUL[1] = mul[i];
		MOD = prime[i];
		for (int j = 2;j <= ret1.size();j++)
			MUL[j] = MUL[j - 1] * MUL[1] % MOD;
		if (!ok())
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}