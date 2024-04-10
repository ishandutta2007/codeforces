#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 2e4+10;
const int INF = 0x3f3f3f3f;

std::map<char, int> c[MN];
int l[MN], d[MN], A, B, X, ra, rb, ca[MN], cb[MN], dis[MN];
char a[MN], b[MN];
bool vis[MN];

int get(int p, char x, int q)
{
	if(p==-1)
		return 0;
	else if(d[q] == d[p]+1)
		return q;
	else
	{
		std::map<char, int>::iterator it;
		int r=++X;
		c[r]=c[q], l[r]=l[q], d[r]=d[p]+1;
		l[q]=r;
		for(;p!=-1 && (it=c[p].find(x))->second == q;p=l[p])
			it->second=r;
		return r;
	}
}

int append(int p, char x)
{
	std::map<char, int>::iterator it;
	if((it=c[p].find(x)) != c[p].end())
		return get(p, x, it->second);

	int n=++X;
	for(;p!=-1 && (it=c[p].find(x))==c[p].end();p=l[p])
		c[p].insert({x, n});
	l[n] = get(p, x, it->second);
	return n;
}

void bfs()
{
	memset(dis, -1, sizeof dis);
	dis[0]=0;
	std::queue<int> q;
	q.push(0);
	for(int n;!q.empty();)
	{
		n=q.front(); q.pop();
		for(auto x:c[n])
			if(dis[x.second] == -1)
				dis[x.second] = dis[n]+1, q.push(x.second);
	}
}

void dfs(int n=0)
{
	if(vis[n]) return;
	vis[n]=1;
	for(auto x:c[n])
	{
		dfs(x.second);
		ca[n]+=ca[x.second];
		cb[n]+=cb[x.second];
	}
	//printf("%d: %d %d\n", n, ca[n], cb[n]);
}
int main()
{
	l[0]=-1;
	scanf(" %s %s", a, b);
	for(;a[A];++A) ra = append(ra, a[A]);
	for(;b[B];++B) rb = append(rb, b[B]);

	for(;ra!=0;ra=l[ra]) ++ca[ra];
	for(;rb!=0;rb=l[rb]) ++cb[rb];
	bfs();
	dfs();

	int ans=INF;
	for(int i=1;i<=X;++i)
		if(ca[i] == 1 && cb[i] == 1)
			ckmin(ans, dis[i]);

	if(ans==INF) ans=-1;
	printf("%d\n", ans);
	return 0;
}