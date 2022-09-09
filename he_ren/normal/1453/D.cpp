#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline int get_num1(ll x)
{
	int res = 0;
	while(x)
	{
		if(x&1) ++res;
		x >>= 1;
	}
	return res;
}

void solve(void)
{
	ll d;
	scanf("%lld",&d);
	if(d&1){ printf("-1\n"); return;}
	
	for(int i=1; i<=2000; ++i)
	{
		ll x = d + 2 * i;
		if(x&3) continue;
		x >>= 2;
		if(get_num1(x) > i) continue;
		
		priority_queue< int,vector<int>,greater<int> > q;
		for(int j=0; j<=62; ++j)
			if(bdig(x,j)) q.push(j+1);
		int cnt = (int)q.size();
		while(q.size() && cnt < i)
		{
			if(q.top() == 1){ q.pop(); continue;}
			int x = q.top(); q.pop();
			++cnt; q.push(x-1); q.push(x-1);
		}
		
		if(cnt < i) continue;
		vector<int> vec;
		cnt -= q.size();
		while(q.size()) vec.push_back(q.top()), q.pop();
		while(cnt--) vec.push_back(1), q.pop();
		
		int sum = 0;
		for(int j=0; j<(int)vec.size(); ++j) sum += vec[j];
		if(sum > 2000) continue;
		
		printf("%d\n",sum);
		for(int j=0; j<(int)vec.size(); ++j)
		{
			printf("1 ");
			for(int k=1; k<vec[j]; ++k) printf("0 ");
		}
		putchar('\n');
		return;
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}