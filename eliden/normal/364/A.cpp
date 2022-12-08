#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

long long sum[sz], f[sz];
int main()
{
	int a;
	scanf("%d",&a);
	string s;
	cin >> s;
	int ac=0;
	rep(i,0,s.size())
	{
		ac+=s[i]-'0';
		sum[i] = ac;
	}
	rep(i,0,sz)
		f[i]=0;
	int total=0;
	rep(i,0,s.size())
	{
		rep(j,0,i+1)
		{
			int x = sum[i];
			if(j>0)
				x-=sum[j-1];
			++f[x];
			++total;
		}
	}
	long long ans=0;
	if(a==0)
		ans = 2*f[0]*total-f[0]*f[0];
	else
		for(long long j=1;j*j<=a;++j)
			if(a%j==0)
				if(j*j==a)
					ans+=f[j]*f[j];
				else if(a/j<sz)
					ans+=2*f[j]*f[a/j];
	cout<<ans<<endl;
}