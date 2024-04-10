#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

pii a[MAXN];
int b[MAXN], dif[MAXN];

vector< pair<pii,int> > ans;
inline void push_ans(int u,int v,int w){ ans.push_back(make_pair(make_pair(u,v),w));}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i].first), a[i].second = i;
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	
	ll suma = 0, sumb = 0;
	for(int i=1; i<=n; ++i)
		suma += a[i].first, sumb += b[i];
	if(suma != sumb) return printf("NO"), 0;
	
	queue<int> q1, q2;
	for(int i=1; i<=n; ++i)
	{
		dif[i] = b[i] - a[i].first;
		if(dif[i] > 0) q1.push(i);
		if(dif[i] < 0) q2.push(i);
	}
	
	while(q1.size() && q2.size())
	{
		int u = q1.front(), v = q2.front();
		int d = min(dif[u], -dif[v]);
		if(a[u].first + d > a[v].first - d) return printf("NO"), 0;
		
		push_ans(a[u].second, a[v].second, d);
		a[u].first += d; a[v].first -= d;
		dif[u] -= d; dif[v] += d;
		if(!dif[u]) q1.pop();
		if(!dif[v]) q2.pop();
	}
	
	printf("YES\n%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
	return 0;
}