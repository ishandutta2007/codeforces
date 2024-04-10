#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
string s;
int n,t,m,f[100],a[N],c[100];
signed main()
{
	cin>>n>>t>>s;
	for(int i=1;i<=n;i++)
		a[i]=s[i-1]-'a';
	t-=(1<<a[n]);
	t+=(1<<a[n-1]);
	n-=2;
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
		t+=(1<<a[i]);
	}
	if(t<0||t%2)
	{
		cout<<"No"<<endl;
		return 0;
	}
	t>>=1;
	while(t)
	{
		a[m]=t&1;
		t>>=1;
		m++;
	}
	int l=0;
	for(int i=m-1;i>=0;i--)
	{
		l+=a[i];
		int k=min(l,c[i]);
		l-=k;
		c[i]-=k;
		l*=2;
	}
	if(l)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}