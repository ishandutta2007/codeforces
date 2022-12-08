#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

const int MN = 5e2+10; // change to 510

int N, f, ok[MN*MN], ctr, tot;
bool v[MN*MN], maxdeg;
std::vector<int> a[MN*MN];
std::queue<int> q;

void adde(int u, int v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}

void dfs(int n, int p=-1)
{
	if(v[n])
	{
		printf("SICK\n");
		exit(0);
	}
	v[n]=1;
	if(a[n].size()==3) maxdeg=1;
	if(!~ok[n]) ++ctr;
	++tot;
	for(int x:a[n])
		if(x!=p)
			dfs(x, n);
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		int x,y;
		scanf("%d%d", &x, &y);
		x+=2, y+=2;
		int id=x*MN+y;
		auto process=[&](int nx, int ny)
		{
			if(ok[nx*MN+ny]<0)
				f-=2, adde(id, nx*MN+ny);
			else
				ok[nx*MN+ny]++;
		};
		f+=3;
		process(x+1, y);
		process(x-1, y);
		if(x&1) process(x-1, y+1);
		else process(x+1, y-1);
		ok[id]=-1;
	}

	for(int i=0;i<MN*MN;++i)
		if(ok[i]>=2)
			q.push(i);
	for(;!q.empty();)
	{
		int id=q.front(); q.pop();
		int x=id/MN; int y=id-MN*x;
		auto process=[&](int nx, int ny)
		{
			int nid=nx*MN+ny;
			if(ok[nid]<0)
				adde(id, nid);
			else if(++ok[nid]==2)
				q.push(nid);
		};
		process(x+1, y);
		process(x-1, y);
		if(x&1) process(x-1, y+1);
		else process(x+1, y-1);
		ok[id]=-2;
	}

	for(int i=0;i<MN*MN;++i)
		if(!~ok[i] && !v[i])
		{
			tot=ctr=maxdeg=0;
			dfs(i), f-=2;
			if(ctr==3 && tot == 4 && maxdeg) f-=2; // I think this uniquely defines "triforce," as editorial calls it
		}

	printf("RECOVERED\n%d\n", f);
	return 0;
}