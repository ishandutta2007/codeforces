#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int max_P = 2e5;

ll a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%lld",&b[i]);
	
	if(n==1)
	{
		if(a[1]==b[1]) printf("SMALL\n0\n");
		else printf("IMPOSSIBLE");
		return 0;
	}
	if(n==2)
	{
		string ans;
		ll tot=0;
		
		while(1)
		{
			if(b[1]==a[1] && b[2]==a[2]) break;
			if(b[2]==a[1] && b[1]==a[2])
			{
				ans += 'R';
				break;
			}
			
			if(b[1]==b[2])
			{
				printf("IMPOSSIBLE");
				return 0;
			}
			
			if(b[1]>b[2])
			{
				if(tot<=max_P) ans += 'R';
				swap(b[1],b[2]);
			}
			
			if(a[1]<=a[2] && a[1]==b[1] && (b[2]-a[2]) % b[1] == 0)
			{
				tot += (b[2]-a[2])/b[1];
				if(tot <= max_P)
					ans += string((b[2]-a[2])/b[1], 'P');
				break;
			}
			
			swap(a[1],a[2]);
			if(a[1]<=a[2] && a[1]==b[1] && (b[2]-a[2]) % b[1] == 0)
			{
				tot += (b[2]-a[2])/b[1];
				if(tot <= max_P)
					ans += string((b[2]-a[2])/b[1], 'P');
				ans += 'R';
				break;
			}
			swap(a[1],a[2]);
			
			tot += b[2]/b[1];
			if(tot <= max_P)
				ans += string(b[2]/b[1], 'P');
			b[2] %= b[1];
			
			if(!b[2]){ printf("IMPOSSIBLE"); return 0;}
		}
		
		if(tot <= max_P)
		{
			reverse(ans.begin(),ans.end());
			printf("SMALL\n%d\n",(int)ans.size());
			cout<<ans;
		}
		else printf("BIG\n%lld",tot);
		return 0;
	}
	
	string ans;
	int tot=0;
	
	while(1)
	{
		bool flag=1;
		for(int i=1; i<=n; ++i)
			if(b[i]!=a[i])
			{
				flag=0;
				break;
			}
		if(flag) break;
		
		reverse(b+1,b+n+1);
		flag=1;
		for(int i=1; i<=n; ++i)
			if(b[i]!=a[i])
			{
				flag=0;
				break;
			}
		if(flag){ ans+='R'; break;}
		reverse(b+1,b+n+1);
		
		flag=1;
		for(int i=2; i<=n; ++i)
			if(b[i-1] >= b[i])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			ans += 'P';
			++tot;
			for(int i=n; i>1; --i)
				b[i] -= b[i-1];
			continue;
		}
		
		reverse(b+1,b+n+1);
		flag=1;
		for(int i=2; i<=n; ++i)
			if(b[i-1] >= b[i])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			ans += "RP";
			++tot;
			for(int i=n; i>1; --i)
				b[i] -= b[i-1];
			continue;
		}
		reverse(b+1,b+n+1);
		
		printf("IMPOSSIBLE");
		return 0;
	}
	
	if(tot <= max_P)
	{
		reverse(ans.begin(),ans.end());
		printf("SMALL\n%d\n",(int)ans.size());
		cout<<ans;
	}
	else printf("BIG\n%d",tot);
	return 0;
}