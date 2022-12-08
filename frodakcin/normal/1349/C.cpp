#include <cstdio>
#include <cstring>
#include <queue>

using ll = long long;
const int MN = 1e6, dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
int a[MN], b[MN], d[MN], R, C, Q;
std::queue<int> q;
char s[MN];

int main(void)
{
	memset(d, -1, sizeof d);
	scanf("%d%d%d", &R, &C, &Q);
	for(int i=0;i<R;++i)
	{
		scanf(" %s", s);
		for(int j=0;j<C;++j)
			a[i*C+j]=s[j]=='1';
	}
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
		{
			int id=i*C+j;
			bool good = (i && a[id-C]==a[id]) || (j && a[id-1]==a[id]) || (i+1<R && a[id+C]==a[id]) || (j+1<C && a[id+1]==a[id]);
			if(good)
				q.push(id), d[id]=0, b[id]=a[id];
		}
	for(int n,x,y;!q.empty();)
	{
		n=q.front(); q.pop();
		x=n/C, y=n-C*x;
		for(int i=0;i<4;++i)
		{
			int nx=x+dx[i], ny=y+dy[i], nid=nx*C+ny;
			if(nx < 0 || R <= nx || ny < 0 || C <= ny || ~d[nid])
				continue;
			d[nid]=d[n]+1;
			b[nid]=b[n];
			q.push(nid);
		}
	}
	for(int i=0,x,y,id;i<Q;++i)
	{
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		--x, --y;
		id=x*C+y;
		if(!~d[id] || t <= d[id])
			printf("%d\n", a[id]);
		else
			printf("%d\n", b[id]^(int)(t&1));
	}
	return 0;
}