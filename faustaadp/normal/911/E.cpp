#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n,k,i,a[202020],b[202020],ma,hv,tt,tv,hn,ht;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=k;i++)
		cin>>a[i];
	tt=k;
	stack<ll> st;
	hv=1;
	for(i=1;i<=k;i++)
	{
		if(a[i]==hv)
		{
			b[a[i]]=1;
			hv++;
		}
		else
		if(st.empty()||st.top()>a[i])
			st.push(a[i]);
		else
		{
			cout<<-1<<"\n";
			return 0;
		}
		while(!st.empty()&&st.top()==hv)
		{
			st.pop();
			hv++;
		}
	}
	hn=hv;
	while(!st.empty())
	{
		ht=st.top();
		st.pop();
		for(i=ht-1;i>=hn;i--)
		{
			tt++;
			a[tt]=i;
		}
		hn=ht+1;
	}
	tv=n;
	for(i=tt+1;i<=n;i++)
	{
		a[i]=tv;
		tv--;
	}
	for(i=1;i<=n;i++)
		if(i<n)
			cout<<a[i]<<" ";
		else
			cout<<a[n]<<"\n";
}