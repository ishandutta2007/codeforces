#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll linf = 0x3f3f3f3f;

inline vector<int> read_a(int n)
{
	vector<int> res(n);
	for(int i=0; i<n; ++i) scanf("%d",&res[i]);
	return res;
}
inline ll get_sum(const vector<int> &a)
{
	ll res = 0;
	for(int i=0; i<(int)a.size(); ++i) res += a[i];
	return res;
}

vector<int> a[4];

int main(void)
{
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	a[1] = read_a(n1); a[2] = read_a(n2); a[3] = read_a(n3);
	
	for(int i=1; i<=3; ++i) sort(a[i].begin(),a[i].end());
	ll s1 = get_sum(a[1]), s2 = get_sum(a[2]), s3 = get_sum(a[3]);
	
	ll ans = s1 + s2 + s3 - min(s1, min(s2,s3)) * 2;
	for(int i=1; i<=3; ++i) if((int)a[i].size() >= 2)
		for(int j=1; j<=3; ++j) if(j!=i)
			ans = max(ans, s1 + s2 + s3 - a[i][0] * 2 - a[j][0] * 2);
	printf("%lld",ans);
	return 0;
}