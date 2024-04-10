#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXD = 2e5 + 5;

int a[MAXN],c[MAXD];
vector<int> ans[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&c[i]);
	
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	
	int tot=1;
	for(int i=1; i<=n; ++i)
	{
		int l=1, r=tot+1;
		while(l<r)
		{
			int mid = (l+r)>>1;
			if((int)ans[mid].size() >= c[a[i]]) l=mid+1;
			else r=mid;
		}
		
		ans[l].push_back(a[i]);
		if(l>tot) tot=l;
	}
	
	printf("%d\n",tot);
	for(int i=1; i<=tot; ++i)
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0; j<(int)ans[i].size(); ++j) printf("%d ",ans[i][j]);
		putchar('\n');
	}
	return 0;
}