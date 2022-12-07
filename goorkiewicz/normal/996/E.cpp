#include <bits/stdc++.h>
using namespace std;

struct LLI 
	{
	public:
	int x;
	int y;
	int inx;
	
	LLI (int X = 0, int Y = 0, int INX = 0) {
		x=X; y=Y; inx=INX;
		}
	};

int n, i, j;
LLI now;
LLI p [100001];
bool out [100001];
bool OUT [100001];

inline long long dist (LLI a) {
	long long X = ((long long)(a.x));
	long long Y = ((long long)(a.y));
	return ((X*X)+(Y*Y));
	}

inline LLI Plus (LLI a, LLI b) {
	return LLI (a.x+b.x,a.y+b.y);
	}

inline LLI Minus (LLI a, LLI b) {
	return LLI (a.x-b.x,a.y-b.y);
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		{
		scanf ("%d%d",&p[i].x,&p[i].y);
		p[i].inx = i;
		if (p[i].x<0 || (p[i].x==0 && p[i].y<0))
			{
			p[i].x *= (-1);
			p[i].y *= (-1);
			out[i] = true;
			}
		}
	now = LLI (0,0,0);
	do
		{
		for (i=0; i!=n; i++)
			OUT[i]=out[i];
		now = LLI (0,0,0);
		random_shuffle(p,p+n);
		for (i=0; i!=n; i++)
			{
			if (dist(Plus(now,p[i])) <= dist(Minus(now,p[i])))
				now = Plus (now,p[i]);
			else
				{
				now = Minus (now,p[i]);
				OUT[p[i].inx] = (!OUT[p[i].inx]);
				}
			}
		} while (dist(now)>(1500000LL * 1500000LL));
	for (i=0; i!=n; i++)
		printf ("%d ",OUT[i]==true ? 1 : (-1));
	printf ("\n");
	return 0;
	}