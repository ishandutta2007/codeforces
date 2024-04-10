#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
bitset<2000>b;
int main(){
	n=read(),m=read();
	if(n>=m){puts("YES");return 0;}
	for(int i=1;i<=n;i++)
	{
		int a=read();
		if(!a){puts("YES");return 0;}
		a%=m;b|=b<<a;
		b|=b>>m;
		b[a]=1;
	}
	if(b[0])puts("YES");
	else puts("NO");
	return 0;
}