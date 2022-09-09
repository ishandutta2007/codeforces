#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 15 + 5;
const int MAXM = 15 + 5;
const int ALL = 1e4 + 5;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

char s[MAXN][MAXM];

int d = 0, xs[12], ys[12];

inline int get_chg(int a,int b,int c)
{
	int tmp = xs[a] * (ys[b] - ys[c]) + xs[b] * (ys[c] - ys[a]) + xs[c] * (ys[a] - ys[b]);
	return tmp == 0? 0: tmp > 0? 1: 2;
}

inline int get_direc(int p,int q)
{
	for(int k=0; k<4; ++k)
		if(xs[p] + dx[k] == xs[q] && ys[p] + dy[k] == ys[q])
			return k;
	return -1;
}

inline int get_mask(int beg = 0)
{
	int mask = get_direc(beg + 1, beg + 2);
	for(int i=1; i+2 <= d; ++i)
		mask = mask * 3 + get_chg(beg + i, beg + i+1, beg + i+2);
	return mask;
}

int dis[MAXN][MAXM][ALL];
queue< pair<pii, int> > q;
inline void set_dis(int x,int y,int mask,int k)
{
	if(!dis[x][y][mask])
		dis[x][y][mask] = k,
		q.push(make_pair(make_pair(x,y),mask));
}

inline void build_snake(int x,int y,int mask)
{
	xs[1] = x; ys[1] = y;
	
	static int delta[12];
	for(int i=d; i>=3; --i)
		delta[i] = mask % 3, mask /= 3;
	xs[2] = xs[1] + dx[mask]; ys[2] = ys[1] + dy[mask];
	
	for(int i=3; i<=d; ++i)
		for(int k=0; k<4; ++k)
		{
			xs[i] = xs[i-1] + dx[k]; ys[i] = ys[i-1] + dy[k];
			if(xs[i] == xs[i-2] && ys[i] == ys[i-2]) continue;
			
			if(get_chg(i-2, i-1, i) == delta[i]) break;
		}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j] >= '0' && s[i][j] <= '9')
			{
				xs[s[i][j] - '0'] = i;
				ys[s[i][j] - '0'] = j;
				d = max(d, s[i][j] - '0');
			}
	
	set_dis(xs[1], ys[1], get_mask(), 1);
	while(q.size())
	{
		int x = q.front().first.first, y = q.front().first.second, mask = q.front().second;
		q.pop();
		
		int cur = dis[x][y][mask];
		build_snake(x,y,mask);
		
		for(int k=0; k<4; ++k)
		{
			int xx = xs[1] + dx[k], yy = ys[1] + dy[k];
			if(!s[xx][yy] || s[xx][yy] == '#') continue;
			
			if(s[xx][yy] == '@')
				return printf("%d",cur), 0;
			
			bool ok = 1;
			for(int i=2; i<d; ++i)
				if(xs[i] == xx && ys[i] == yy){ ok = 0; break;}
			if(!ok) continue;
			
			xs[0] = xx; ys[0] = yy;
			set_dis(xx, yy, get_mask(-1), cur + 1);
		}
	}
	
	printf("-1");
	return 0;
}