#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

inline int ask(const vector<int> &vec)
{
	printf("? %d ",(int)vec.size());
	for(int i=0; i<(int)vec.size(); ++i)
		printf("%d ",vec[i]);
	putchar('\n');
	fflush(stdout);
	
	int res;
	scanf("%d",&res);
	if(res==-1) exit(0);
	return res;
}

inline int ask(int l,int r)
{
	printf("? %d ",r-l+1);
	for(int i=l; i<=r; ++i)
		printf("%d ",i);
	putchar('\n');
	fflush(stdout);
	
	int res;
	scanf("%d",&res);
	if(res==-1) exit(0);
	return res;
}

inline void answer(const vector<int> &vec)
{
	printf("! ");
	for(int i=0; i<(int)vec.size(); ++i)
		printf("%d ",vec[i]);
	putchar('\n');
	fflush(stdout);
	
	string res;
	cin>>res;
	if(res[0] != 'C') exit(0);
}

int gao(int l,int r,int mx)
{
	if(l==r) return l;
	int mid = (l+r)>>1;
	if(ask(l,mid) == mx) return gao(l,mid,mx);
	else return gao(mid+1,r,mx);
}

vector<int> a[MAXN];
vector<int> ans;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=d; ++i)
	{
		int c;
		scanf("%d",&c);
		a[i].resize(c);
		for(int j=0; j<c; ++j)
			scanf("%d",&a[i][j]);
	}
	
	int mx = ask(1,n);
	int pos = gao(1,n,mx);
	
	ans.resize(d);
	for(int i=1; i<=d; ++i)
	{
		bool flag=0;
		for(int j=0; j<(int)a[i].size(); ++j)
			if(a[i][j] == pos)
			{
				flag=1;
				break;
			}
		if(flag)
		{
			static bool in[MAXN];
			for(int j=1; j<=n; ++j) in[j] = 0;
			
			for(int j=0; j<(int)a[i].size(); ++j)
				in[a[i][j]] = 1;
			
			vector<int> vec;
			for(int j=1; j<=n; ++j)
				if(!in[j]) vec.push_back(j);
			ans[i-1] = ask(vec);
		}
		else ans[i-1] = mx;
	}
	answer(ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}