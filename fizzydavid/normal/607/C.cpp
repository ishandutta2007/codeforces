//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
char s[1000111],t[1000111];
int n,id[256],a[1000111],b[1000111];
int main()
{
	id['N']=0;
	id['S']=1;
	id['E']=2;
	id['W']=3;
	scanf("%d",&n);
	n--;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;i++)a[i]=id[s[i]],b[i]=id[t[i]]^1;
	ll B=rand()+6;
	ll hs1=0,hs2=0,bs=1;
	for(int i=n;i>=1;i--)
	{
		hs1=(hs1*B+a[i])%mod;
		hs2=(hs2+b[i]*bs)%mod;
		bs=bs*B%mod;
		if(hs1==hs2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}