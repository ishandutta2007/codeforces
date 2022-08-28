#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;

const int MAXN = 200005;

struct Vector
{
	ll x,y;
	
	db arc()
	{
		return atan2(y,x);
	}
}v[MAXN];

ll cross(Vector a,Vector b)
{
	return a.x * b.y - a.y * b.x;
}

bool operator < (const Vector &a,const Vector &b)
{
	return cross(a,b) > 0;
}

Vector max(Vector a,Vector b)
{
	return a < b ? b : a;
}

Vector min(Vector a,Vector b)
{
	return a < b ? a : b;
}

struct Seg
{
	Vector l,r;
	int id;
	
	bool operator < (const Seg &p)const
	{
		return l < p.l;
	}
};

int n,H;

db ans;
int x[MAXN];
int y[MAXN];

set<Seg> s;

pair<db,db> getcoord(int u,db t)
{
	db k = (db)(y[u] - y[u + 1]) / (x[u] - x[u + 1]);
	db b = y[u] - k * x[u];
	pair<db,db> res;
	res.first = b / (tan(t) - k);
	res.second = tan(t) * res.first;
	return res;
}

db dist(pair<db,db> a,pair<db,db> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

db len(int u,Vector l,Vector r)
{
	if (!cross((Vector){x[u] - x[u + 1],y[u] - y[u + 1]},l) && !cross(l,r))
		return dist(make_pair(x[u],y[u]),make_pair(x[u + 1],y[u + 1]));
	return dist(getcoord(u,l.arc()),getcoord(u,r.arc()));
}

int main()
{
	scanf("%d%d",&n,&H);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&x[i],&y[i]);
	int X = x[n],Y = y[n] + H;
	for (int i = 1;i <= n;i++)
	{
		x[i] = X - x[i],y[i] = Y - y[i];
		v[i] = (Vector){x[i],y[i]};
	}
	for (int i = 1;i < n;i++)
	{
		Vector theta1 = v[i];
		Vector theta2 = v[i + 1];
		if (!(theta1 < theta2))
			continue;
		set<Seg>::iterator it = s.lower_bound((Seg){theta1,theta2,i});
		if (it != s.begin())
			it--;
		while (it != s.end())
		{
			Vector l = it->l,r = it->r;
			int u = it->id;
			if (theta2 < l)
				break;
			Vector L = max(theta1,l),R = min(theta2,r);
			if (L < R)
			{
				ans -= len(u,L,R);
			}
			set<Seg>::iterator nxt = it;
			nxt++;
			s.erase(it);
			if (l < L)
				s.insert((Seg){l,L,u});
			if (R < r)
				s.insert((Seg){R,r,u});
			it = nxt;
		}
		s.insert((Seg){theta1,theta2,i});
		ans += len(i,theta1,theta2);
	}
	for (int i = 1;i < n;i++)
	{
		Vector theta1 = v[i];
		Vector theta2 = v[i + 1];
		if (cross(theta1,theta2) == 0)
		{
			set<Seg>::iterator it = s.lower_bound((Seg){theta1,theta2,i});
			bool t1 = 0,t2 = 0,t3 = 1;
			t1 = (it == s.end() || theta1 < it->l || it->id < i);
			if (it != s.end())
			{
				if (it->l < theta1 && theta1 < it->r)
					t3 = 0;
			}
			t2 = (it == s.begin());
			if (it != s.begin())
			{
				it--;
				if (it->l < theta1 && theta1 < it->r)
					t3 = 0;
				t2 = (it->r < theta2 || it->id < i);
			}
			if ((t1 || t2) && t3)
				ans += len(i,theta1,theta2);
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}