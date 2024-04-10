#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0');if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w; 
}
const int xx=2e5+5;
char s[xx],t[xx];
int v1[xx],v2[xx];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	int n=strlen(s+1);
	int m=strlen(t+1);
	int now=1;
	for(int i=1;i<=n;i++)if(t[now]==s[i])v1[now]=i,now++;
	now--;
	for(int i=n;i>=1;i--)if(t[now]==s[i])v2[now]=i,now--;
	int ans=0;
	v2[m+1]=n+1;
	for(int i=0;i<=m;i++)ans=max(ans,v2[i+1]-v1[i]-1);
	cout<<ans<<"\n";
	return 0;
}