#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,A1,A2,i,ta,h1,h2;
pair<ll,ll> a[303030];
bool ubah;
bool cek1(ll aa)
{
	return ((a[aa].fi*aa)>=A1);
}
bool cek2(ll aa)
{
	return ((a[aa].fi*(aa-h1))>=A2);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A1>>A2;
	for(i=1;i<=n;i++)
	{
		cin>>ta;
		a[i]=mp(ta,i);
	}
	if(A1<A2)
	{
		ubah=1;
		swap(A1,A2);
	}	
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	h1=-1;
	h2=-1;
	for(i=1;i<=n;i++)
		if(cek1(i))
		{
			h1=i;
			break;
		}
	for(i=h1+1;i<=n;i++)
		if(cek2(i))
		{
			h2=i;
			break;
		}
	//cout<<h1<<" "<<h2<<"\n";
	if(h1==-1||h2==-1)
	{
		ubah=1-ubah;
		swap(A1,A2);
		h1=-1;
		h2=-1;
		for(i=1;i<=n;i++)
		if(cek1(i))
		{
			h1=i;
			break;
		}
		for(i=h1+1;i<=n;i++)
		if(cek2(i))
		{
			h2=i;
			break;
		}
	}
	if(h1==-1||h2==-1)
	{
		cout<<"No\n";
		return 0;
	}
	else
	{
		cout<<"Yes\n";
		if(!ubah)
		{
			cout<<h1<<"\n"<<h2-h1<<"\n";
			for(i=1;i<=h1;i++)
				if(i<h1)
					cout<<a[i].se<<" ";
				else
					cout<<a[i].se<<"\n";
			for(i=h1+1;i<=h2;i++)
				if(i<h2)
					cout<<a[i].se<<" ";
				else
					cout<<a[i].se<<"\n";	
		}
		else
		{
			cout<<h2-h1<<"\n"<<h1<<"\n";
			for(i=h1+1;i<=h2;i++)
				if(i<h2)
					cout<<a[i].se<<" ";
				else
					cout<<a[i].se<<"\n";
			for(i=1;i<=h1;i++)
				if(i<h1)
					cout<<a[i].se<<" ";
				else
					cout<<a[i].se<<"\n";	
		}
	}
	
}