#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Vector
{
	int x,y;
	Vector(void){}
	Vector(int _x,int _y): x(_x), y(_y) {}
};
typedef Vector Point;

inline bool operator == (const Vector &p,const Vector &q){ return p.x == q.x && p.y == q.y;}
inline Vector operator - (const Vector &p,const Vector &q){ return Vector(p.x - q.x, p.y - q.y);}
inline ll cross(const Vector &p,const Vector &q){ return (ll)p.x * q.y - (ll)p.y * q.x;}
inline ldb dist(const Point &p,const Point &q){ return sqrtl((ll)(p.x-q.x) * (p.x-q.x) + (ll)(p.y-q.y) * (p.y-q.y));}

inline bool coline(const Point &p1,const Point &p2,const Point &p3)
{
	return cross(p2 - p1, p3 - p1) == 0;
}

Point p[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	
	if(n == 1){ printf("0\n"); return 0;}
	if(n == 2){ printf("%.20lf\n",(double)dist(p[1], p[2])); return 0;}
	if(n == 3)
	{
		swap(p[d], p[1]);
		ldb ans1 = dist(p[1], p[2]) + dist(p[2], p[3]);
		ldb ans2 = dist(p[1], p[3]) + dist(p[3], p[2]);
		printf("%.20lf\n",(double)min(ans1, ans2));
		return 0;
	}
	
	Vector v1, v2;
	if(coline(p[1], p[2], p[3])) v1 = p[1], v2 = p[2];
	else if(coline(p[2], p[3], p[4])) v1 = p[2], v2 = p[3];
	else if(coline(p[1], p[3], p[4])) v1 = p[1], v2 = p[3];
	else v1 = p[1], v2 = p[2];
	
	Point pd = p[d];
	int sp = d;
	for(int i=1; i<=n; ++i)
		if(!coline(v1, v2, p[i]))
		{
			sp = i;
			break;
		}
	swap(p[sp], p[n]);
	
	sort(p+1,p+n,[](Point pp,Point qq){
		return pp.x == qq.x? pp.y < qq.y: pp.x < qq.x;
	});
	d = find(p+1,p+n+1, pd) - p;
	
	if(d == n)
	{
		ldb ans = min(dist(p[n], p[1]), dist(p[n], p[n-1])) + dist(p[n-1], p[1]);
		printf("%.20lf\n",(double)ans);
		return 0;
	}
	
	auto cmp_dis = [&](Point pp,Point qq)
	{
		return dist(pp, p[n]) < dist(qq, p[n]);
	};
	
	int mid1 = min_element(p+1,p+n,cmp_dis) - p;
	int mid2;
	if(mid1 == 1) mid2 = mid1 + 1;
	else if(mid1 == n - 1) mid2 = mid1 - 1;
	else mid2 = cmp_dis(p[mid1-1], p[mid1+1])? mid1 - 1: mid1 + 1;
	
	vector<int> vec = {1, n-1, mid1, mid2, d};
	if(d > 1) vec.push_back(d - 1);
	if(d < n - 1) vec.push_back(d + 1);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	vector<pii> must;
	for(int i=0; i+1<(int)vec.size(); ++i)
		if(vec[i+1] - vec[i] != 1)
			must.emplace_back(vec[i], vec[i+1]);
	
	vec.push_back(n);
	ldb ans = 1e18;
	do
	{
		if(vec[0] != d) continue;
		static int pos[MAXN];
		for(int i=0; i<(int)vec.size(); ++i)
			pos[vec[i]] = i;
		bool ok = 1;
		for(pii cur: must)
			if(abs(pos[cur.first] - pos[cur.second]) != 1)
			{
				ok = 0;
				break;
			}
		if(!ok) continue;
		
		ldb cur = 0;
		for(int i=0; i+1<(int)vec.size(); ++i)
			cur += dist(p[vec[i]], p[vec[i+1]]);
		ans = min(ans, cur);
	}while(next_permutation(vec.begin(), vec.end()));
	
	printf("%.20lf",(double)ans);
	return 0;
}