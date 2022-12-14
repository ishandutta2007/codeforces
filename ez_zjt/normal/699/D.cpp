#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 200010
using namespace std;

int n;
int p[MAXN],f[MAXN];
vector<int> S;

int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

int main()
{
	int cnt=0,root=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",p+i);
		if(p[i]==i && !root)
		{
			++cnt;
			root=i;
			continue;
		}
		if(getf(p[i])==getf(i))
		{
			S.push_back(i);
		}else{
			f[f[p[i]]]=f[i];
		}
	}
	int ans=S.size();
	if(!cnt)
		root=S[0];
	for(int i=0;i<S.size();i++)
		p[S[i]]=root;
	printf("%d\n", ans);
	for(int i=1;i<=n;i++)
		printf("%d ", p[i]);
	return 0;
}