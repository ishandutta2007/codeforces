#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXG = 3e3 * 3e3 * 2 + 5;
const int MAXP = MAXN * 2;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,1,-1,1,-1};

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int R,C;
int encode(int x,int y){ return x * C + y;}

int fa[MAXP], siz[MAXP], sta_tm[MAXP], curtm = 0;
int find(int u){ return fa[u] == u? u: find(fa[u]);}
void connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return;
	if(siz[u] > siz[v]) swap(u, v);
	fa[u] = v; siz[v] += siz[u];
	sta_tm[++curtm] = u;
}
void roll_back(int t)
{
	while(curtm > t)
	{
		int u = sta_tm[curtm--], v = fa[u];
		fa[u] = u; siz[v] -= siz[u];
	}
}

int main(void)
{
	int n;
	R = read(); C = read(); n = read();
	if(R == 1) return printf("%d",min(C-1, n)), 0;
	if(C == 1) return printf("0"), 0;
	
	C *= 2;
	for(int i=1; i<=2*n; ++i) fa[i] = i, siz[i] = 1;
	
	static int id[MAXG];
	auto walk = [&] (int x,int y,int k)
	{
		int xx = x+dx[k], yy = y+dy[k];
		if(yy < 0) yy = C-1;
		if(yy >= C) yy = 0;
		return encode(xx, yy);
	};
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = read() - 1, y = read() - 1;
		int u1 = i * 2 - 1, u2 = u1 + 1;
		
		int save = curtm;
		bool ok = 1;
		for(int k=0; k<8; ++k) if(x+dx[k]>=0 && x+dx[k]<R)
		{
			int v1 = id[walk(x, y, k)];
			int v2 = v1 & 1? v1 + 1: v1 - 1;
			if(v1)
			{
				connect(u1, v1); connect(u2, v2);
				if(find(u1) == find(u2))
				{
					roll_back(save);
					ok = 0;
					break;
				}
			}
		}
		
		if(ok)
		{
			id[encode(x, y)] = u1;
			id[encode(x, y+C/2)] = u2;
			++ans;
		}
	}
	
	printf("%d",ans);
	return 0;
}