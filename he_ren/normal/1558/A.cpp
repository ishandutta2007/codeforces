#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> get(int p,int q,int a)
{
	vector<int> res;
	for(int i=0; i<=a; ++i) if(i <= q && a - i <= p)
		res.push_back(i + p - (a - i));
	return res;
}

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int tot = a + b;
	vector<int> res = get(tot / 2, tot - tot / 2, a);
	vector<int> res2 = get((tot + 1) / 2, tot - (tot + 1) / 2, a);
	res.insert(res.end(), res2.begin(), res2.end());
	
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	
	printf("%d\n",(int)res.size());
	for(int i=0; i<(int)res.size(); ++i)
		printf("%d ",res[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}