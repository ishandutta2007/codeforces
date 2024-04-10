#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int get(int x)
{
	int res = 0;
	while(x) ++res, x /= 10;
	return res;
}

void solve(void)
{
	int x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	
	int t = min(y, b);
	y -= t; b -= t;
	
	int p = get(x) + y, q = get(a) + b;
	if(p != q)
	{
		putchar(p > q? '>': '<');
		putchar('\n');
		return;
	}
	
	while(y--) x *= 10;
	while(b--) a *= 10;
	
	putchar(x == a? '=': x > a? '>': '<');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}