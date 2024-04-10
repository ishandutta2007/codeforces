#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

vector<int> oper;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=2*n; ++i)
	{
		static char s[10];
		scanf("%s",s+1);
		
		if(s[1] == '+') oper.push_back(0);
		else
		{
			int x;
			scanf("%d",&x);
			oper.push_back(x);
		}
	}
	
	vector<int> ans;
	set<int> t;
	
	for(int i=(int)oper.size()-1; i>=0; --i)
	{
		int x = oper[i];
		if(x)
		{
			if(!t.empty() && *t.begin() <= x)
				return printf("NO"), 0;
			t.insert(x);
		}
		else
		{
			if(t.empty())
				return printf("NO"), 0;
			ans.push_back(*t.begin());
			t.erase(t.begin());
		}
	}
	
	printf("YES\n");
	for(int i=n-1; i>=0; --i)
		printf("%d ",ans[i]);
	return 0;
}