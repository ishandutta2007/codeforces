#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector< pair<int,pii> > vec;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			if(a[i] >= a[j]) vec.push_back(make_pair(a[i] - a[j], make_pair(i,j)));
			else vec.push_back(make_pair(a[j] - a[i], make_pair(j,i)));
		}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int u = vec[i].second.first, v = vec[i].second.second;
		printf("? %d %d\n",u,v);
		fflush(stdout);
		
		static char s[10];
		scanf("%s",s+1);
		if(s[1] == 'Y')
		{
			printf("! %d %d",u,v);
			fflush(stdout);
			return 0;
		}
	}
	printf("! 0 0");
	fflush(stdout);
	return 0;
}