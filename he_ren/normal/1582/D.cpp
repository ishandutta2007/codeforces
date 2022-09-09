#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXA = 1e4 + 5;

inline int sgn(int x){ return x < 0? -1: 1;}

int a[MAXN], b[MAXN];
bool del[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(del,0,n+1);
	static int t[MAXA];
	memset(t, 0, sizeof(t));
	vector<pii> p;
	for(int i=1; i<=n; ++i)
	{
		int x = abs(a[i]);
		if(t[x])
		{
			int j = t[x];
			del[i] = del[j] = 1;
			if(sgn(a[j]) == sgn(a[i]))
				b[j] = -1, b[i] = 1;
			else
				b[j] = b[i] = 1;
			t[x] = 0;
			p.push_back(make_pair(i, j));
		}
		else t[x] = i;
	}
	
	vector<int> pos;
	for(int i=1; i<=n; ++i) if(!del[i])
		pos.push_back(i);
	
	if(pos.size() == 1)
	{
		pos.push_back(p.back().first);
		pos.push_back(p.back().second);
	}
	
	for(int i=0; i<(int)pos.size(); i+=2)
	{
		if(i+3 == (int)pos.size())
		{
			int x = pos[i], y = pos[i+1], z = pos[i+2];
			bool flag = 0;
			if(a[y] + a[z] == 0) a[z] = -a[z], flag = 1;
			
			int k = a[y] + a[z];
			b[x] = -k; b[y] = b[z] = a[x];
			
			if(flag) b[z] = -b[z];
			break;
		}
		else
		{
			int x = pos[i], y = pos[i+1];
			b[x] = -a[y]; b[y] = a[x];
		}
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",b[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}