#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;

const int SZ=2e5;
const ll Q = 1e9+7;
bool filled[SZ], cycle[SZ], root[SZ], vis[SZ], issink[SZ], mark[SZ];
int to[SZ], ancs[SZ], sink[SZ];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,2*n)
	{
		filled[i] = false;
		cycle[i] = false;
		root[i] = true;
		vis[i]  = false;
		issink[i] = true;
		mark[i] = false;
		ancs[i] = 0;
		sink[i] = i;
	}
	rep(i,0,n)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		issink[x] = false;
		filled[x] = true;
		root[y] = false;
		to[x] = y;
	}
	ll tot=1;
	rep(i,0,2*n)
		if(!vis[i] && filled[i])
		{
			int j;
			for(j=i;!vis[j] && filled[j];j=to[j]) // good
				vis[j] = true, mark[j]=true;
			if(mark[j])
			{
				int c=1;
				cycle[j] = true;
				for(int k=to[j];k!=j;k=to[k]) // !
					++c, cycle[k]=true;
				tot*=min(c,2), tot%=Q;
			}
			for(int k=i;mark[k];k=to[k]) // good
				mark[k] = false;
		}
	rep(i,0,2*n)
		if(filled[i] && root[i])
		{
			int d=0, j;
			for(j=i;!cycle[j] && !issink[j];j=to[j]) // ?
				++d;
			if(!cycle[j])
			{
				for(int k=i;k!=j;k=to[k]) // !
				{
					sink[k] = sink[j];
					issink[k] = true;
				}
				ancs[sink[i]]+=d;
			}
			else
				for(j=i;!cycle[j];j=to[j]) // good
					cycle[j] = true;
		}
	rep(i,0,2*n)
		tot*=ancs[i]+1, tot%=Q;
	cout << tot << endl;
}