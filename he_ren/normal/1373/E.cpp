#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const ll linf = 0x3f3f3f3f3f3f3f3f;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	if(!d)
	{
		string ans;
		while(n)
			ans.push_back(min(n, 9) + '0'),
			n -= min(n,9);
		reverse(ans.begin(), ans.end());
		cout<<ans<<endl;
		return;
	}
	
	ll ans = linf;
	for(int low=0; low<=9; ++low)
	{
		int cnt=0, now=0;
		for(int i=0; i<=d; ++i)
		{
			now += (low+i)%10;
			if(low+i > 9) ++cnt;
		}
		if(now > n) continue;
		
		for(int tot9=0; tot9<=16; ++tot9)
		{
			try
			{
				int res = now + tot9 * 9 * (d+1-cnt);
				
				if(res > n) continue;
				if(n - res - cnt < 0 || (n - res - cnt) % (d+1)) continue;
				
				int x = (n - res - cnt) / (d+1);
				
				ll tmp = 0, now = 1;
				while(x)
				{
					if(now==1)
						tmp = tmp + min(x,8) * now,
						x -= min(x,8);
					else
						tmp = tmp + min(x,9) * now,
						x -= min(x,9);
					now *= 10;
					
					if(tmp >= ans) throw 114514;
				}
				
				for(int i=1; i<=tot9; ++i)
				{
					tmp = tmp*10 + 9;
					if(tmp >= ans) throw 114514;
				}
				tmp = tmp*10 + low;
				
				ans = min(ans, tmp);
			}
			catch(...){ continue;}
		}
	}
	if(ans == linf) printf("-1\n");
	else printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}