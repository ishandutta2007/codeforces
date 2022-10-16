#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll n,k;
char c[1000005];
char s[1000005];
signed main(){
	n=read();k=read();
	scanf("%s",c+1);scanf("%s",s+1);
	ll maxx=1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		maxx<<=1;
		if(c[i]=='b')maxx--;
		if(s[i]=='a')maxx--;
		if(maxx>k)
		{
			ans+=(n-i+1)*k;
			break;
		}
		ans+=maxx;
	}
	cout<<ans<<endl;
	return 0;
}