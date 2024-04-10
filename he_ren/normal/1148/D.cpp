#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int n;
int a[MAXN],b[MAXN];

inline vector<int> get_res(void)
{
	vector<pii> vec;
	for(int i=1; i<=n; ++i) if(a[i] < b[i])
		vec.push_back(make_pair(-a[i], i));
	sort(vec.begin(),vec.end());
	
	vector<int> res(vec.size());
	for(int i=0; i<(int)vec.size(); ++i) res[i] = vec[i].second;
	return res;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	vector<int> res1 = get_res();
	for(int i=1; i<=n; ++i) swap(a[i], b[i]);
	vector<int> res2 = get_res();
	reverse(res2.begin(),res2.end());
	
	if(res2.size() > res1.size()) res1 = res2;
	printf("%d\n",(int)res1.size());
	for(int i=0; i<(int)res1.size(); ++i)
		printf("%d ",res1[i]);
	return 0;
}