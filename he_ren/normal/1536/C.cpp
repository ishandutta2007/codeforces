#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

struct Data
{
	int a,b;
	Data(void){}
	Data(int _a,int _b): a(_a), b(_b) {}
	inline bool operator < (const Data &oth) const
	{
		return (ll)a * oth.b < (ll)b * oth.a;
	}
	inline bool operator == (const Data &oth) const
	{
		return (ll)a * oth.b == (ll)b * oth.a;
	}
};

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int x = 0, y = 0;
	map<Data,int> t;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == 'D') ++x;
		else ++y;
		printf("%d ",++t[Data(x,y)]);
	}
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}