#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

char s[MAXN];
int to[MAXN], dep[MAXN], idx[MAXN];
int siz[MAXN];
ll f[MAXN];
vector<int> pt[MAXN];
vector<ll> sumf[MAXN];

inline ll get(int k,int l,int r)
{
	ll res = sumf[k][r];
	if(l) res -= sumf[k][l-1];
	int len = r-l+1;
	res += (ll)len * (len+1) / 2;
	return res;
}

int main(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	stack<int> sta;
	int mxd = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i] == '(') sta.push(i);
		else
		{
			if(!sta.size()) continue;
			int j = sta.top(); sta.pop();
			to[i] = j; to[j] = i;
			dep[i] = dep[j] = (int)sta.size() + 1;
			mxd = max(mxd, dep[i]);
			
			idx[i] = idx[j] = (int)pt[dep[i]].size();
			pt[dep[i]].push_back(j);
		}
	}
	
	for(int k=mxd; k>=1; --k)
	{
		sumf[k].resize(pt[k].size());
		for(int i=0; i<(int)pt[k].size(); ++i)
		{
			int l = pt[k][i], r = to[l];
			if(l+1 == r) f[l] = f[r] = 0;
			else
			{
				assert(dep[l+1] == dep[r-1]);
				f[l] = f[r] = get(k+1, idx[l+1], idx[r-1]);
			}
			
			sumf[k][i] = f[l];
			if(i) sumf[k][i] += sumf[k][i-1];
		}
	}
	
	while(Q--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		printf("%lld\n",get(dep[l], idx[l], idx[r]));
	}
	return 0;
}