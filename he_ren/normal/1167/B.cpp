#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a[10] = {4,8,15,16,23,42};

void solve(void)
{	
	vector<int> ans;
	vector<int> vis(100,0);
	
	for(int i=1; i<5; ++i)
	{
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		int res;
		scanf("%d",&res);
		
		int x,y;
		for(int j=0; j<6; ++j)
			for(int k=0; k<j; ++k)
				if(a[j] * a[k] == res)
					x = a[j],
					y = a[k];
		if(vis[x]) ans.push_back(x), ans.push_back(y);
		else if(vis[y]) ans.push_back(y), ans.push_back(x);
		++vis[x]; ++vis[y];
	}
	
	for(int i=0; i<(int)ans.size(); ++i)
		vis[ans[i]] = 2;
	
	printf("! ");
	for(int i=0; i<6; ++i)
		if(vis[a[i]] == 1) printf("%d ",a[i]);
	
	for(int i=0; i<(int)ans.size(); ++i)
		if(i==0 || ans[i] != ans[i-1])
			printf("%d ",ans[i]);
	
	for(int i=0; i<6; ++i)
		if(vis[a[i]] == 0) printf("%d ",a[i]);
	fflush(stdout);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}