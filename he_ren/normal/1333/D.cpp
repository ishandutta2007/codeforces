#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 3e3 + 5;
const int MAXP = MAXN*MAXN;

vector<int> g[MAXP];
int deg[MAXP],dep[MAXP];
inline void add(int u,int v)
{
	g[u].push_back(v);
	++deg[v];
	dep[v] = max(dep[v], dep[u]+1);
}

int n,d;
char s[MAXN];
int cnt=0,lst[MAXN];
vector<int> oper;

void init(void)
{
	static char t[MAXN];
	for(int i=1; i<=n; ++i) t[i] = s[i];
	
	oper.push_back(0);
	while(1)
	{
		bool flag=0;
		for(int i=1; i<n; ++i)
		{
			if(t[i]=='R' && t[i+1]=='L')
			{
				++cnt;
				t[i]='L'; t[i+1]='R';
				
				dep[cnt] = 1;
				if(lst[i]) add(lst[i],cnt);
				if(lst[i+1]) add(lst[i+1],cnt);
				
				oper.push_back(i);
				lst[i] = lst[i+1] = cnt;
				
				flag=1;
			}
		}
		if(!flag) break;
	}
}

queue<int> q;

int main(void)
{
	scanf("%d%d%s",&n,&d,s+1);
	
	init();
	if(cnt < d){ printf("-1"); return 0;}
	int mxDep=0;
	for(int i=1; i<=cnt; ++i)
		mxDep = max(mxDep, dep[i]);
	if(mxDep > d){ printf("-1"); return 0;}
	
	for(int i=1; i<=cnt; ++i)
		if(!deg[i]) q.push(i);
	int rem = cnt, tmp = d;
	
	while(!q.empty())
	{
		if(rem < tmp){ printf("-1"); return 0;}
		
		vector<int> now;
		--tmp;
		int mx = q.size();
		for(int k=1; k<=mx && rem > tmp; ++k)
		{
			int u = q.front(); q.pop(); --rem;
			now.push_back(oper[u]);
			
			for(int i=0; i<(int)g[u].size(); ++i)
			{
				int v = g[u][i];
				--deg[v];
				if(!deg[v]) q.push(v);
			}
		}
		
		printf("%d ",(int)now.size());
		for(int i=0; i<(int)now.size(); ++i)
			printf("%d ",now[i]);
		putchar('\n');
	}
	return 0;
}