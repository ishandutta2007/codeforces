#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e5 + 5;

int n, L;
int a[MAXN];

inline bool chk(int need)
{
	if(need == 0) return 1;
	int id = n - need + 1;
	vector<pii> vec;
	for(int i=id,j=id; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		vec.emplace_back(a[i], j-i);
	}
	
	vec.emplace_back(L, 0);
	int pos, cnt = 0, oth = 0;
	for(int i=0; i+1<(int)vec.size(); ++i)
	{
		pos = vec[i].first; cnt += vec[i].second;
		int nxt = vec[i+1].first;
		if(oth + (ll)(nxt - pos) * cnt >= nxt)
			return 0;
		oth += (ll)(nxt - pos) * cnt;
	}
	return 1;
}

void solve(void)
{
	scanf("%d%d",&L,&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int l = 0, r = n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}