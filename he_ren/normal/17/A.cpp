#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

inline bool isp(int x)
{
	for(int i=2; i<x; ++i)
		if(x%i == 0) return 0;
	return 1;
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	vector<int> p;
	for(int i=2; i<=n; ++i)
		if(isp(i)) p.push_back(i);
	
	int cnt = 0;
	for(int i=0; i<(int)p.size(); ++i)
		for(int j=0; j<i; ++j)
			if(p[i] == p[j] + p[j+1] + 1){ ++cnt; break;}
	
	if(cnt >= d) printf("YES");
	else printf("NO");
	return 0;
}