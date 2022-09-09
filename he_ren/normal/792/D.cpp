#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long ll;
const int MAXM = 1e5 + 5;
using namespace std;

char s[MAXM];
#define lowbit(x) ((x)&-(x))

int main(void)
{
	ll n;
	int q;
	cin>>n>>q;
	while(q--)
	{
		ll u;
		cin>>u>>s;
		int m=strlen(s);
		for(int i=0; i<m; ++i)
		{
			if(s[i]=='U')
			{
				if(u==((n+1)>>1)) continue;
				ll b=lowbit(u);
				u = (u^b)|(b<<1);
			}
			else if(s[i]=='L')
			{
				if(u&1) continue;
				ll b=lowbit(u);
				u = (u^b)|(b>>1);
			}
			else
			{
				if(u&1) continue;
				ll b=lowbit(u);
				u = u|(b>>1);
			}
		}
		cout<<u<<endl;
	}
	return 0;
}