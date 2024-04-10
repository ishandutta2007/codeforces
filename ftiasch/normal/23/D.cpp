// Codeforces Beta Round #23
// Problem D -- Tetragon
#include <cmath>
#include <vector>
#include <cstdio>
#include <utility>

#define EPS 1e-7

#define X first
#define Y second
#define POINT pair<double, double>

using namespace std;

int t;
POINT p[3];

double product(POINT O, POINT A, POINT B)
{
	return (A.X - O.X) * (B.Y - O.Y) - (B.X - O.X) * (A.Y - O.Y);
}

POINT reflect(POINT O, POINT A)
{
	return POINT(2 * O.X - A.X, 2 * O.Y - A.Y);
}

POINT center(POINT A, POINT B, POINT C)
{
	double D = 2 * (A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y));
	double OX = ((A.Y * A.Y + A.X * A.X) * (B.Y - C.Y) + (B.Y * B.Y + B.X * B.X) * (C.Y - A.Y) + (C.Y * C.Y + C.X * C.X) * (A.Y - B.Y)) / D;
	double OY = ((A.Y * A.Y + A.X * A.X) * (C.X - B.X) + (B.Y * B.Y + B.X * B.X) * (A.X - C.X) + (C.Y * C.Y + C.X * C.X) * (B.X - A.X)) / D;
	return POINT(OX, OY);
}

vector<POINT> solve(POINT A, POINT B, POINT C)
{
	vector<POINT> tmp;
	tmp.clear();
	if(fabs(product(reflect(A, B), A, C)) <= EPS)
		return tmp;
	tmp.push_back(center(reflect(A, B), A, C));
	if(fabs(product(reflect(A, C), A, B)) <= EPS)
		return tmp;
	tmp.push_back(center(reflect(A, C), A, B));
	tmp.push_back(reflect(B, tmp[1]));
	tmp.push_back(reflect(C, tmp[0]));
	return tmp;
}

bool check(vector<POINT> p)
{
	if(p.size() != 4)
		return false;
	for(int i = 0; i != 4; ++ i)
		if(product(p[i], p[(i + 1) % 4], p[(i + 2) % 4]) * product(p[i], p[(i + 1) % 4], p[(i + 3) % 4]) <= EPS)
			return false;
	return true;
}

int main()
{
	for(scanf("%d", &t); t; -- t)
	{
		for(int i = 0; i != 3; ++ i)
			scanf("%lf%lf", &p[i].X, &p[i].Y);
		bool flag = false;
		for(int i = 0; i != 3; ++ i)
		{
			vector<POINT> tmp = solve(p[i], p[(i + 1) % 3], p[(i + 2) % 3]);
			if(check(tmp))
			{
				printf("YES\n");
				for(vector<POINT>::iterator iter = tmp.begin(); iter != tmp.end(); ++ iter)
					printf("%.10f %.10f ", iter->X, iter->Y);
				printf("\n");
				flag = true;
				break;
			}
		}
		if(!flag)
			printf("NO\n\n");
	}
	return 0;
}