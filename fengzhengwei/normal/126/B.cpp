#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
char s[xx];
int z[xx];
int t[xx];
signed main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int l(0),r(0);
	for(int i=2;i<=n;i++)
	{
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])z[i]++;
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
	z[1]=n;
	for(int i=1;i<=n;i++)t[z[i]]++;
	for(int i=n-1;i>=1;i--)t[i]+=t[i+1];
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(i+z[i]-1==n&&t[z[i]]>=3)ans=max(ans,z[i]);
	}
	if(ans==-1)puts("Just a legend");
	else 
	{
		for(int i=1;i<=ans;i++)cout<<s[i];
		puts("");
	}
	return 0;
}