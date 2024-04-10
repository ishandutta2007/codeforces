#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	if(n % 2)
	{
		printf("-1\n");
		return;
	}
	
	vector<pii> oper;
	vector<int> seg;
	for(int i=n; i>=1;)
	{
		int pos = i-1;
		while(pos && a[pos] != a[i]) --pos;
		if(pos == 0)
		{
			printf("-1\n");
			return;
		}
		for(int j=i-1, k=pos-1; j>pos; --j)
		{
			oper.emplace_back(k, a[j]);
			++k;
		}
		seg.push_back((i-pos) * 2);
		
		for(int j=pos; j<i; ++j) a[j] = a[j+1];
		reverse(a+pos, a+i-1);
		i -= 2;
	}
	reverse(seg.begin(), seg.end());
	
	printf("%d\n",(int)oper.size());
	for(pii t: oper) printf("%d %d\n",t.first,t.second);
	printf("%d\n",(int)seg.size());
	for(int x: seg) printf("%d ",x);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}