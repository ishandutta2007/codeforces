#include <iostream>
#include <cstdio>

#include <cmath>
#include <cassert>

using namespace std;

const int MN = 2e3 + 100;

#define ti(X) static_cast<int>(X)
using ll = long double;
#define tl(X) static_cast<ll>(X)

int N;
int p[MN][2];
bool u[MN];
int t;
char s[MN];

ll get(ll a, ll b, ll c, ll d)
{
	//assert(a*d!=b*c);
	return a*d-b*c;
}

int main(void)
{
	scanf("%d", &N);
	t = -1;
	for(int i = 0;i < N;i++)
	{
		scanf("%d%d", p[i], p[i]+1);
		if(!~t||p[i][0]<p[t][0]) t=i;
	}
	scanf(" %s", s);
	printf("%d ", t+1);
	u[t] = 1;
	bool c;
	for(int i = 0;i < N-2;i++)
	{
		c = s[i]=='R';
		int x = -1;
		for(int j = 0;j < N;j++)
			if(!u[j])
			{
				if(!~x) x = j;
				else
				{
					if(c&&get(p[x][0]-p[t][0], p[x][1]-p[t][1], p[j][0]-p[t][0], p[j][1]-p[t][1])>0) x=j;
					if(!c&&get(p[j][0]-p[t][0], p[j][1]-p[t][1], p[x][0]-p[t][0], p[x][1]-p[t][1])>0) x=j;
				}
			}
		u[t=x] = 1;
		printf("%d ", t+1);
	}
	for(int i = 0;i < N;i++)
		if(!u[i])
			printf("%d\n", i+1);
	return 0;
}