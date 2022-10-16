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
const int xx=1e5+5;
int n;
int a[xx];
int l[xx];
int r[xx];
int L[xx];
int R[xx];
int preL[xx];
int preR[xx];
int sufL[xx];
int sufR[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	a[0]=n+1;
	a[n+1]=n+1;
	for(int i=1;i<=n;i++)if(a[i-1]<a[i])l[i]=1+l[i-1];// 
	for(int i=n;i>=1;i--)if(a[i+1]<a[i])r[i]=1+r[i+1];// 
	a[0]=0;
	a[n+1]=0;
	for(int i=1;i<=n;i++)if(a[i-1]>a[i])L[i]=1+L[i-1];// 
	for(int i=n;i>=1;i--)if(a[i+1]>a[i])R[i]=1+R[i+1];// 
	int ans=0;
	for(int i=1;i<=n;i++)preL[i]=max(preL[i-1],L[i]);
	for(int i=1;i<=n;i++)preR[i]=max(preR[i-1],R[i]);
	for(int i=n;i>=1;i--)sufL[i]=max(sufL[i+1],L[i]);
	for(int i=n;i>=1;i--)sufR[i]=max(sufR[i+1],R[i]);
	for(int i=1;i<=n;i++)//ai 
	{
		if(!l[i]||!r[i])continue;
		int maxx=max(preL[i],max(sufR[i],max(preR[i-l[i]-1],sufL[i+r[i]+1])));
		if(maxx>=max(l[i],r[i]))continue;
//		cout<<i<<" "<<l[i]<<" "<<r[i]<<"\n";
		if(l[i]-(!(l[i]&1))>=r[i])continue;
		if(r[i]-(!(r[i]&1))>=l[i])continue;
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}