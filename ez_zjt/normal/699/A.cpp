#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 200010
#define INF 0x7FFFFFFF
using namespace std;

int n;
vector<int> a,b;
char str[MAXN];
int pos[MAXN];

int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
		scanf("%d",pos+i);
	for(int i=1;i<=n;i++)
		if(str[i]=='R')
			a.push_back(pos[i]);
		else
			b.push_back(pos[i]);
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int now=0;
	int ans=INF;
	for(int i=0;i<b.size();i++)
	{
		while(now<a.size() && a[now]<=b[i])
			now++;
		if(now)
			ans=min(ans,b[i]-a[now-1]);
	}
	if(ans==INF)
		printf("-1\n");
	else
		printf("%d\n", ans/2);
}