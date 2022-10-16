#include<bits/stdc++.h>
#define ll long long
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
int n;
const int xx=1e6+5;
ll a[xx],b[xx];
pair<int,int>t[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()+a[i-1];
	for(int i=1;i<=n;i++)b[i]=read()+b[i-1];
	int op=0;
	if(a[n]>b[n])swap(a,b),op=1;
	int tp=0;
	for(int i=0;i<n;i++)t[i].first=-1;
	for(int i=0;i<=n;i++)
	{
		while(a[i]-b[tp]>=n)tp++;
		if(t[a[i]-b[tp]].first==-1)
		{
			t[a[i]-b[tp]].first=i;
			t[a[i]-b[tp]].second=tp;
		}
		else 
		{
			if(op)
			{
				cout<<tp-t[a[i]-b[tp]].second<<"\n";
				for(int j=t[a[i]-b[tp]].second+1;j<=tp;j++)cout<<j<<" \n"[j==tp];
				cout<<i-t[a[i]-b[tp]].first<<"\n";
				for(int j=t[a[i]-b[tp]].first+1;j<=i;j++)cout<<j<<" \n"[j==i];
			}
			else 
			{
				cout<<i-t[a[i]-b[tp]].first<<"\n";
				for(int j=t[a[i]-b[tp]].first+1;j<=i;j++)cout<<j<<" \n"[j==i];
				cout<<tp-t[a[i]-b[tp]].second<<"\n";
				for(int j=t[a[i]-b[tp]].second+1;j<=tp;j++)cout<<j<<" \n"[j==tp];
			}
			return 0;
		}
	}
	return 0;
}