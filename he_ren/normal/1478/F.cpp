#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;

inline ll dist(pii p,pii q){ return (ll)(p.first - q.first) * (p.first - q.first) + (ll)(p.second - q.second) * (p.second - q.second);}

pii p[MAXN];
bool del[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first,&p[i].second);
	
	printf("1 ");
	pii cur = p[1]; del[1] = 1;
	for(int k=1; k<n; ++k)
	{
		ll mxd = -1;
		int res = -1;
		for(int i=1; i<=n; ++i)
			if(!del[i] && dist(cur, p[i]) > mxd)
				mxd = dist(cur, p[i]), res = i;
		del[res] = 1;
		cur = p[res];
		printf("%d ",res);
	}
	return 0;
}