#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
const int MAXK = 2e5 + 5;
using namespace std;

queue<int> q;
map<int,bool> t;
int a[MAXK],cnt=0;

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(t.find(x)!=t.end()) continue;
		
		q.push(x); t[x]=1;
		if((int)q.size()>k)
		{
			t.erase(q.front());
			q.pop();
		}
	}
	printf("%d\n",(int)q.size());
	while(!q.empty()) a[++cnt]=q.front(), q.pop();
	for(int i=cnt; i>=1; --i) printf("%d ",a[i]);
	return 0;
}