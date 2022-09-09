#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int get_res(vector<int> &a,vector<int> &b)
{
	if(!a.size() || !b.size()) return 0;
	
	vector<int> suf(a.size() + 1);
	set<int> t(b.begin(), b.end());
	for(int i=(int)a.size()-1; i>=0; --i)
		suf[i] = suf[i+1] + (t.find(a[i]) != t.end());
	
	vector<int> fir(a.size());
	for(int i=0; i<(int)a.size(); ++i)
		fir[i] = a[i] - i;
	
	int ans = suf[0];
	for(int i=0; i<(int)b.size(); ++i)
	{
		int pos = upper_bound(fir.begin(), fir.end(), b[i]) - fir.begin() - 1;
		if(pos < 0) continue;
		
		int cnt = upper_bound(b.begin(),b.end(),b[i] + pos) - b.begin() - i;
		ans = max(ans, cnt + suf[pos+1]);
	}
	return ans;
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> la, ra, lb, rb;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x<0) la.push_back(-x);
		else ra.push_back(x);
	}
	for(int i=1; i<=m; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x<0) lb.push_back(-x);
		else rb.push_back(x);
	}
	
	reverse(la.begin(),la.end());
	reverse(lb.begin(),lb.end());
	printf("%d\n",get_res(la,lb) + get_res(ra,rb));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}