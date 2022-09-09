#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline void upd(int &x,int &y)
{
	int t = min(x - 1, y);
	x -= t; y -= t;
}

void solve(void)
{
	int a,b,c,m;
	scanf("%d%d%d%d",&a,&b,&c,&m);
	
	int t[] = {a,b,c};
	sort(t, t+3);
	for(int i=2; i>=0; --i) upd(t[i], m);
	
	if(m)
	{
		printf("NO\n");
		return;
	}
	
	if(t[2] > t[0] + t[1] + 1) printf("NO\n");
	else printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}