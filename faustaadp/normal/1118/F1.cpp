#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[303030],ta,tb,jum[3],S[3][303030],has;
vector<ll> v[303030];
void dfs(ll aa,ll bb)
{
	ll ii;
	S[1][aa]+=(a[aa]==1);
	S[2][aa]+=(a[aa]==2);
	for(ii=0;ii<v[aa].size();ii++)
		if(v[aa][ii]!=bb)
		{
			dfs(v[aa][ii],aa);
			S[1][aa]+=S[1][v[aa][ii]];
			S[2][aa]+=S[2][v[aa][ii]];
		}
	ll inv[3];
	inv[1]=jum[1]-S[1][aa];
	inv[2]=jum[2]-S[2][aa];
	has+=(!((S[1][aa]>0&&S[2][aa]>0)||(inv[1]>0&&inv[2]>0)));
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)jum[a[i]]++;
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
	}
	dfs(1,1);
	cout<<has<<"\n";
}