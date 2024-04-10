#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = (1<<18) + 5;
const int inf = 0x3f3f3f3f;

#define ls(u) ((u)<<1)
#define rs(u) ((u)<<1|1)

int n;
char s[MAXN];
int a[MAXN<<1], b[MAXN<<1];

int f[MAXN<<1];

inline void push_up(int u)
{
	if(s[u] == '?')
		f[u] = f[ls(u)] + f[rs(u)];
	else if(s[u] == '0')
		f[u] = f[rs(u)];
	else if(s[u] == '1')
		f[u] = f[ls(u)];
}

int main(void)
{
	int d;
	scanf("%d%s",&d,s+1);
	n = 1<<d;
	
	reverse(s+1,s+n);
	for(int i=1; i<=n; ++i) a[n*2-i] = b[n*2-i] = i, f[n*2-i] = 1;
	for(int i=n-1; i>=1; --i)
		a[i] = a[rs(i)], b[i] = b[ls(i)],
		push_up(i);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int q;
		static char t[10];
		scanf("%d%s",&q,t+1);
		q = n - q;
		
		s[q] = t[1];
		while(q) push_up(q), q >>= 1;
		printf("%d\n",f[1]);
	}
	return 0;
}