#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

const long long MOD = 1000000007;

struct Matrix
{
	int r,c;
	long long a[3][3];
	Matrix(){}
	Matrix(int r_,int c_)
	{
		r = r_;
		c = c_;
		memset(a,0,sizeof(a));
	}
	Matrix operator * (const Matrix & p)const
	{
		Matrix ret = Matrix(r,p.c);
		for (int i = 0;i < ret.r;i++)
			for (int j = 0;j < ret.c;j++)
				for (int k = 0;k < c;k++)
					(ret.a[i][j] += a[i][k] * p.a[k][j]) %= MOD;
		return ret;
	}
}t[8],st,unit;

long long n,m;
long long a[10005];
long long l[10005];
long long r[10005];
long long cnt[3];

vector<pair<pair<long long,int>,int> > event;

Matrix power(Matrix a,long long b)
{
	if (!b)
		return unit; 
	Matrix ret = power(a,b >> 1);
	ret = ret * ret;
	if (b & 1)
		return ret * a;
	return ret; 
}

int main()
{
	ios::sync_with_stdio(false);
	unit = Matrix(3,3);
	unit.a[0][0] = unit.a[1][1] = unit.a[2][2] = 1;
	st = Matrix(3,1);
	st.a[1][0] = 1;
	for (int i = 0;i < 8;i++)
	{
		t[i] = Matrix(3,3);
		t[i].a[0][0] = t[i].a[0][1] = 1;
		t[i].a[1][0] = t[i].a[1][1] = t[i].a[1][2] = 1;
		t[i].a[2][1] = t[i].a[2][2] = 1;
		for (int j = 0;j < 3;j++)
			if (i & (1 << j))
				t[i].a[j][0] = t[i].a[j][1] = t[i].a[j][2] = 0;
	}
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> l[i] >> r[i];
		a[i]--;
		event.push_back(make_pair(make_pair(l[i],i),1));
		event.push_back(make_pair(make_pair(r[i] + 1,i),-1));
	}
	long long last = 1,now = 0;
	sort(event.begin(),event.end());
	for (int i = 0;i < event.size();i++)
	{
		long long pos = event[i].first.first,ori = event[i].first.second,val = event[i].second;
		cnt[a[ori]] += val;
		st = power(t[now],pos - last - 1) * st;
		now = 0;
		if (cnt[0])
			now++;
		if (cnt[1])
			now += 2;
		if (cnt[2])
			now += 4;
		last = pos - 1;
	}
	st = power(t[now],m - last) * st;
	cout << st.a[1][0] << endl;
	return 0;
}