#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const ldb pi = acosl(-1);

struct Vector
{
	ldb x,y;
	Vector(void){}
	Vector(ldb _x,ldb _y): x(_x), y(_y) {}
};
typedef Vector Point;

inline Vector operator + (const Vector &p,const Vector &q){ return Vector(p.x + q.x, p.y + q.y);}
inline Vector operator - (const Vector &p,const Vector &q){ return Vector(p.x - q.x, p.y - q.y);}
inline Vector operator * (const Vector &p,const ldb k){ return Vector(p.x * k, p.y * k);}
inline Vector rotate(const Vector &p,const ldb d){ return Vector(cosl(d) * p.x - sinl(d) * p.y, sinl(d) * p.x + cosl(d) * p.y);}

int main(void)
{
	int n;
	scanf("%d",&n);
	if(n <= 4) return printf("No solution"), 0;
	
	Point cur(0, 0);
	Vector dir(1, 0);
	ldb len = 500, deg = 2 * pi / n;
	
	printf("0 0\n");
	for(int i=1; i<=n-2; ++i)
	{
		len += 0.01;
		dir = rotate(dir, deg);
		cur = cur + dir * len;
		printf("%.20lf %.20lf\n",(double)cur.x,(double)cur.y);
	}
	dir = rotate(dir, deg);
	
	printf("%.20lf 0",(double)(cur.x - cur.y / dir.y * dir.x));
	return 0;
}