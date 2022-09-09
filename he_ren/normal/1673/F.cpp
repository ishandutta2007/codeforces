#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 32 + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int lb[MAXN];

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int n, d;
	scanf("%d%d",&n,&d);
	
	for(int i=0; i<n; ++i, putchar('\n'))
		for(int j=0; j+1<n; ++j)
		{
			int k = lb[lowbit(j+1)];
			printf("%d ",1<<(2*k+1));
		}
	for(int i=0; i+1<n; ++i, putchar('\n'))
		for(int j=0; j<n; ++j)
		{
			int k = lb[lowbit(i+1)];
			printf("%d ",1<<(2*k));
		}
	fflush(stdout);
	
	int x = 0;
	while(d--)
	{
		int _x;
		scanf("%d",&_x);
		x ^= _x;
		
		int A = 0, B = 0, cA = 0, cB = 0;
		for(int i=9; i>=0; --i)
		{
			int k = bdig(x, i);
			if(i & 1)
			{
				cB ^= k;
				B ^= cB << (i / 2);
			}
			else
			{
				cA ^= k;
				A ^= cA << (i / 2);
			}
		}
		
		printf("%d %d\n",A+1,B+1);
		fflush(stdout);
	}
	return 0;
}