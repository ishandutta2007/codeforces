#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int gao(vector<int> a,vector<int> b)
{
	vector<int> vec;
	
	while(a.size() && b.size())
	{
		if(a.back() > b.back())
			vec.push_back(0), a.pop_back();
		else
			vec.push_back(1), b.pop_back();
	}
	while(a.size()) vec.push_back(0), a.pop_back();
	while(b.size()) vec.push_back(1), b.pop_back();
	
	int res = 0;
	for(int i=0,j=0; i<(int)vec.size(); i=j)
	{
		while(j<(int)vec.size() && vec[j] == vec[i]) ++j;
		++res;
	}
	
	if(res&1) res^=1;
	return res;
}

char s[MAXN];
vector<int> pos[10 + 5];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	for(int i=0; i<=9; ++i) pos[i].clear();
	for(int i=1; i<=n; ++i)
		pos[s[i]-'0'].push_back(i);
	
	int mxl = 0;
	for(int i=0; i<=9; ++i)
		mxl = max(mxl, (int)pos[i].size());
	for(int i=0; i<=9; ++i)
		for(int j=0; j<i; ++j)
			mxl = max(mxl, gao(pos[i], pos[j]));
	printf("%d\n",n-mxl);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}