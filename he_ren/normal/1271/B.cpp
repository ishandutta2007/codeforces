#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
typedef unsigned int uint;
const int MAXN = 200 + 5;

int n;
char s[MAXN],t[MAXN];
vector<int> ans;

void gao(void)
{
	ans.clear();
	for(int i=1; i<=n; ++i) s[i]=t[i];
	
	for(int i=1; i<n; ++i)
		if(s[i]=='W' && s[i+1]=='W')
			s[i]=s[i+1]='B',
			ans.push_back(i);
	for(int i=1; i<n; ++i)
		if(s[i]=='W')
		{
			if(s[i+1]=='B')
			{
				s[i]='B';
				s[i+1]='W';
				ans.push_back(i);
			}
			else
			{
				s[i]=s[i+1]='B';
				ans.push_back(i);
			}
		}
	if(s[n]=='W') return;
	printf("%d\n",(int)ans.size());
	for(uint i=0; i<ans.size(); ++i)
		printf("%d ",ans[i]);
	exit(0);
}

int main(void)
{
	scanf("%d%s",&n,t+1);
	gao();
	for(int i=1; i<=n; ++i)
	{
		if(t[i]=='B') t[i]='W';
		else t[i]='B';
	}
	gao();
	printf("-1");
	return 0;
}