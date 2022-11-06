#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll x,i,has,a[110];
ll tanya()
{
	ll H=0,ii;
	cout<<"?";
	for(ii=1;ii<=100;ii++)
		cout<<" "<<a[ii];
	cout<<endl;
	ll y=rand()%100+1;
	cin>>H;
	//H=(x^a[y]);
	return H;
}
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	x=9999;
	ll K1=0,K2=0,K3=(1<<7);
	//cout<<K3<<"\n";
	for(i=0;i<7;i++)
		K1+=(1<<i);
	for(i=7;i<14;i++)
		K2+=(1<<i);
	for(i=1;i<=100;i++)a[i]=i;
	ll tem=tanya();
	//cout<<tem<<"\n";
	tem=(tem&K2);
	has=tem;
	//cout<<tem<<"\n";
	for(i=1;i<=100;i++)a[i]=i*K3;
	tem=tanya();
	tem=(tem&K1);
	has+=tem;
	cout<<"! "<<has<<endl;
}