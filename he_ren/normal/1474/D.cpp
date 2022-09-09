#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];

void get_f(int f[])
{
	f[0] = f[n+1] = 0;
	for(int i=1; i<=n; ++i) f[i] = -1;
	
	for(int i=1; i<=n; ++i)
	{
		if(a[i] >= f[i-1]) f[i] = a[i] - f[i-1];
		else break; 
	}
}

bool chk(int a[])
{
	for(int i=1; i<=4; ++i) if(a[i] < 0) return 0;
	for(int i=2; i<=4; ++i)
	{
		if(a[i] < a[i-1]) return 0;
		a[i] -= a[i-1];
	}
	return !a[4];
}

int f[MAXN], g[MAXN];
void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	get_f(f);
	reverse(a+1,a+n+1);
	get_f(g);
	reverse(a+1,a+n+1); reverse(g+1,g+n+1);
	
	if(f[n] == 0 || g[1] == 0){ printf("YES\n"); return;}
	for(int i=1; i<n; ++i)
	{
		static int b[10];
		b[1] = f[i-1]; b[2] = a[i+1]; b[3] = a[i]; b[4] = g[i+2];
		if(chk(b)){ printf("YES\n"); return;}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}