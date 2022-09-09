#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e5;

vector<int> vec;

void solve(void)
{
	int k;
	scanf("%d",&k);
	printf("%d\n",vec[k-1]);
}

int main(void)
{
	for(int i=1; i<=maxn; ++i)
		if(i%3 && i%10 != 3) vec.push_back(i);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}