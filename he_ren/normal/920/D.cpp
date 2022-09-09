#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const int MAXD = 5e3 + 5;

struct Oper
{
	int c,x,y;
	Oper(void){}
	Oper(int _c,int _x,int _y): c(_c), x(_x), y(_y) {}
};

vector<Oper> trim(const vector<Oper> &vec)
{
	vector<Oper> res;
	for(int i=0; i<(int)vec.size(); ++i)
		if(vec[i].c) res.push_back(vec[i]);
	return res;
}

int a[MAXN];
int f[MAXN][MAXD];

void solve(void)
{
	int n,d,V;
	scanf("%d%d%d",&n,&d,&V);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	if(accumulate(a+1,a+n+1,0) < V)
	{
		printf("NO\n");
		return;
	}
	
	if(V % d == 0)
	{
		vector<Oper> ans;
		for(int i=1; i<n; ++i) ans.push_back(Oper(1e9, i, n));
		ans.push_back(Oper(V / d, n, 1));
		ans = trim(ans);
		
		printf("YES\n");
		for(int i=0; i<(int)ans.size(); ++i)
			printf("%d %d %d\n",ans[i].c,ans[i].x,ans[i].y);
		return;
	}
	
	memset(f[0], 0, sizeof(f[0]));
	f[0][0] = 1;
	for(int i=1; i<=n; ++i)
	{
		memset(f[i], 0, sizeof(f[i]));
		for(int j=0; j<d; ++j) if(f[i-1][j])
		{
			f[i][j] = 1;
			f[i][(j + a[i]) % d] = 2;
		}
	}
	
	if(!f[n][V%d])
	{
		printf("NO\n");
		return;
	}
	
	vector<int> pos;
	for(int i=n, j=V%d; i>=1; --i)
		if(f[i][j] == 2)
			pos.push_back(i),
			j = (j - a[i] % d + d) %d;
	sort(pos.begin(), pos.end());
	assert(pos.size());
	
	static bool has[MAXN];
	memset(has, 0, n+1);
	for(int i=0; i<(int)pos.size(); ++i) has[pos[i]] = 1;
	
	vector<Oper> ans;
	int sum = a[pos[0]];
	for(int i=1; i<(int)pos.size(); ++i)
		ans.push_back(Oper(1e9, pos[i], pos[0])),
		sum += a[pos[i]];
	assert(sum % d == V % d);
	
	int emp = pos.size() > 1? pos[1]: -1;
	for(int i=1; i<=n; ++i) if(!has[i])
	{
		if(emp == -1) emp = i;
		else ans.push_back(Oper(1e9, i, emp));
	}
	assert(emp != -1);
	
	if(sum > V)
		ans.push_back(Oper((sum - V) / d, pos[0], emp));
	else if(sum < V)
		ans.push_back(Oper((V - sum) / d, emp, pos[0]));
	
	ans = trim(ans);
	printf("YES\n");
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d %d\n",ans[i].c,ans[i].x,ans[i].y);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}