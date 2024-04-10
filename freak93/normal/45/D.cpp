#include<cstdio>
#define x first
#define y second
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

pair<int,int> a[500];
struct fcomp
{
	bool operator()(int x,int y)
	{
		if(a[x].y!=a[y].y)
			return a[x].y<a[y].y;
		return x<y;
	}
};

multiset<int,fcomp> S;
vector<int> E[10000002];

int i,n,ans[500],x,y,aux;

int main()
{
	scanf("%d",&n);
 	for(i=1;i<=n;++i)
		scanf("%d%d",&x,&y),E[x].push_back(i),E[y+1].push_back(-i),a[i].x=x,a[i].y=y;
	for(i=1;i<=10000000;++i)
	{
		for(vector<int>::iterator it=E[i].begin();it!=E[i].end();++it)
			if(*it<0)
				S.erase(-*it);
			else
				S.insert(*it);
		if(S.size()>0)
			ans[*S.begin()]=i,S.erase(S.begin());
		if(S.size()==0)
		{
			aux=10000001;
			for(int j=1;j<=n;++j)
				if(ans[j]==0)
					aux=min(aux,a[j].x);
			i=max(i,aux-1);
		}
	}
	for(i=1;i<=n;++i)
		printf("%d ",ans[i]);
}