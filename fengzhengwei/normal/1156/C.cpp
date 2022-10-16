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
int n,m;
int vis[1000005];
int a[1000005];
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int r=2;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		while(r<n&&(a[r]-a[i]<m))r++;
		if(a[r]-a[i]<m)continue;
		ans++;r++;
	}
	cout<<min(ans,n/2)<<"\n";
	return 0;
}