#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

int p[MAXN], q[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	static bool vis[MAXN];
	static vector<int> lst[MAXN];
	for(int i=1; i<=n; ++i) if(!vis[i])
	{
		vector<int> a;
		int u = i;
		while(!vis[u])
			vis[u] = 1,
			a.push_back(u),
			u = p[u];
		
		if((int)a.size() % 2 == 0)
		{
			vector<int> &vec = lst[a.size()];
			if(vec.empty()){ vec=a; continue;}
			
			for(int j=0; j<(int)vec.size(); ++j)
				a.push_back(vec[j]);
			vec.clear();
		}
		
		vector<int> b(a.size());
		
		int half = ((int)a.size() + 1)/2;
		for(int j=0; j<half; ++j)
			b[j<<1] = a[j];
		for(int j=half; j<(int)a.size(); ++j)
			b[(j-half)<<1|1] = a[j];
		
		int tot = (int)b.size();
		for(int j=0; j<(int)b.size(); ++j)
			q[b[j]] = b[(j+1)%tot];
	}
	
	for(int i=1; i<=n; ++i)
		if(!lst[i].empty())
			return printf("-1"), 0;
	for(int i=1; i<=n; ++i)
		printf("%d ",q[i]);
	return 0;
}