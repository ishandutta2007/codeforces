#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,dmin=-1,ans,cnt[200005];
bool flag_min=true;
vector<int> vec[200005];
void dfs(int x,int fa,int dep)
{
	if(vec[x].size()==1 && dmin==-1) dmin=(dep%2);
	if(vec[x].size()==1 && (dep%2)!=dmin) flag_min=false;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]!=fa) dfs(vec[x][i],x,dep+1);
	} 
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
	{
		if(vec[i].size()==1) cnt[vec[i][0]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]>=2) ans+=cnt[i]-1;
	}
	if(flag_min) printf("1 ");
	else printf("3 ");
	printf("%d\n",(n-1)-ans);
}