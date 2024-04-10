#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,L[202020],R[202020],vs,asli[2020202],mas[2020202],kel[2020202],jaw[2020202],tempe,hai[2020202];
vector<ll> v;
unordered_map<ll,bool> B;
unordered_map<ll,ll> con;
void ad(ll aa)
{
	if(B[aa]==0)
	{
		v.pb(aa);
		B[aa]=1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>L[i]>>R[i];
		ad(L[i]-1);
		ad(L[i]+1);
		ad(R[i]-1);
		ad(R[i]+1);
		ad(L[i]);
		ad(R[i]);
	}
	sort(v.begin(),v.end());
	vs=v.size();
	for(i=0;i<vs;i++)
	{
		con[v[i]]=i;
		asli[i]=v[i];
	}
	for(i=1;i<=n;i++)
	{
		mas[con[L[i]]]++;
		kel[con[R[i]]]--;
	}
	tempe=0;
	for(i=0;i<vs;i++)
	{
		tempe+=mas[i];
		hai[i]=tempe;
		tempe+=kel[i];
	}
	for(i=0;i+1<vs;i++)
	{
		if(hai[i]==hai[i+1])
		{
			jaw[hai[i]]+=asli[i+1]-asli[i];
		}
		else
			jaw[hai[i]]++;
	}
	for(i=1;i<=n;i++)
		cout<<jaw[i]<<" ";
}