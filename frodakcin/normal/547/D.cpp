#include <cstdio>
#include <cstring>
#include <vector>

const int MN = 2e5+10;
const int MX = 2e5+10;
const int MM = MN*3;

int N, M, d[MX*2], hd[MX*2], to[MM*2], nx[MM*2], cur[MX*2];
char f[MN];
bool v[MX*2], u[MM];
std::vector<int> q;

void adde(int u, int v)
{
	nx[M]=hd[u], to[M]=v;
	hd[u]=M;
	++M;
}
void dfs(int n)
{
	v[n]=1;
	for(int &id=cur[n],x;;)
	{
		while(~id&&u[id/2]) id=nx[id];
		if(!~id) break;
		x=id, u[id/2]=1;
		dfs(to[x]);
		q.push_back(x/2);
	}
}
int main()
{
	memset(hd, -1, sizeof hd);
	scanf("%d", &N);
	for(int i=0,x,y;i<N;++i)
	{
		scanf("%d%d", &x, &y);
		y+=MX;
		adde(x, y);
		adde(y, x);
		++d[x], ++d[y];
	}
	for(int i=1;i<MX*2;++i)
		if(d[i]&1)
			adde(i, 0), adde(0, i);
	memcpy(cur, hd, sizeof hd);
	for(int i=0;i<MX*2;++i)
		if(!v[i])
			dfs(i);
	for(int i=0;i<q.size();++i)
		if(q[i]<N)
			f[q[i]]=i&1?'r':'b';
	printf("%s\n", f);
	return 0;
}