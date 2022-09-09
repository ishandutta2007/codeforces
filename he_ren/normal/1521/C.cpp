#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

inline int ask(int t,int i,int j,int x)
{
	printf("? %d %d %d %d\n",t,i,j,x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int pos = n;
	for(int i=1; i<n; i+=2)
	{
		int res = ask(2, i, i+1, 1);
		if(res >= 3) continue;
		if(res == 1){ pos = i; break;}
		else if(ask(2, i+1, i, 1) == 1){ pos = i+1; break;}
	}
	
	p[pos] = 1;
	for(int i=1; i<=n; ++i) if(i != pos)
		p[i] = ask(1, pos, i, n - 1);
	
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	putchar('\n');
	fflush(stdout);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}