#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 2e5 + 5;

inline ll get_res(vector<ll> &vec,int len)
{
	for(int i=1; i<(int)vec.size(); ++i) vec[i] += vec[i-1];
	
	ll res = 0;
	for(int i=len; i<(int)vec.size(); ++i)
		res = max(res, vec[i] - vec[i-len]);
	return res;
}

ll a[MAXN * 2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<=n; ++i) a[n+i] = a[i];
	
	vector<ll> p(1),q(1);
	for(int i=1; i<=n*2; i+=2) p.push_back(a[i]);
	for(int i=2; i<=n*2; i+=2) q.push_back(a[i]);
	
	int len = n / 2 + 1;
	printf("%lld",max(get_res(p, len), get_res(q, len)));
	return 0;
}