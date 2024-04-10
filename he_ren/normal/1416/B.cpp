#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;

struct Oper
{
	int i,j,x;
};

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll sum = 0;
	for(int i=1; i<=n; ++i)
		sum += a[i];
	if(sum%n){ printf("-1\n"); return;}
	
	vector<Oper> op;
	for(int i=2; i<=n; ++i)
	{
		if(a[i]%i==0)
			op.push_back((Oper){i,1, a[i]/i});
		else
		{
			op.push_back((Oper){1,i, i - a[i]%i});
			a[i] += i - a[i]%i;
			op.push_back((Oper){i,1, a[i]/i});
		}
	}
	
	for(int i=2; i<=n; ++i)
		op.push_back((Oper){1,i, (int)(sum/n)});
	
	printf("%d\n",(int)op.size());
	for(int i=0; i<(int)op.size(); ++i)
		printf("%d %d %d\n",op[i].i,op[i].j,op[i].x);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}