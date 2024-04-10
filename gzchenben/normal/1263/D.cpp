#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n,fa[200005];
bool flag[200005][30]; 
set<int> st;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	fa[fy]=fx;
	for(int i=0;i<26;i++)
	{
		if(flag[fy][i]) flag[fx][i]=true;
	}
	st.erase(fy);
}
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		char tmp;
		while(1)
		{
			scanf("%c",&tmp);
			if(tmp=='\n') break;
			flag[i][tmp-'a']=true;
		}
		fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		st.insert(i);
		for(set<int>::iterator it=st.begin(); it!=st.end(); it++)
		{
			int now=*it;
			if(i==now) continue; 
			for(int j=0;j<26;j++)
			{
				if(flag[i][j] && flag[now][j])
				{
					merge(now,i);
					break;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i) ans++;
	}
	printf("%d\n",ans);
	return 0;
}