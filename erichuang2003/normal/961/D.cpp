#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

struct Point
{
	int x, y;
}P[N];

typedef Point Vector;

Vector operator - (Point A, Point B)
{
    return (Vector){A.x - B.x, A.y - B.y};
}

LL cross(Vector u, Vector v)
{
    return 1ll * u.x * v.y - 1ll * u.y * v.x;
}

int n;
int id[N];

int main() {

	srand(time(0));
	
	scanf("%d", &n);

	if (n <= 4)
	{
		puts("YES");
		return 0;
	}

	For(i, 1, n)
	    scanf("%d%d", &P[i].x, &P[i].y);
	
	int T = 100;
	while (T--)
	{
		int u = rand() % n + 1, v = rand() % (n - 1) + 1;
		if (v >= u) ++v;
		Vector d = P[v] - P[u];

		int m = 0;
		For(i, 1, n) if (cross(d, P[i] - P[u])) id[++m] = i;

		bool flag = true;
		For(i, 1, m - 2)
		    if (cross(P[id[i + 1]] - P[id[i]], P[id[i + 2]] - P[id[i]]))
		    {
		        flag = false;
		        break;
		    }
		if (flag)
		{
			puts("YES");
			return 0;
		}
	}

	puts("NO");

	return 0;
}