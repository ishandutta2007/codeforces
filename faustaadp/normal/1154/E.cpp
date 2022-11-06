#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,a[202020],pos[202020],ki[202020],ka[202020],KI,KA,masih,te,b[202020],i,tbk;
void updki(ll aa,ll bb)
{
	if(aa==0)return ;
	if(bb==0)KI=aa;
	else
	{
	//	cout<<aa<<" "<<tbk<<"\n";
		masih--;
		b[aa]=te;
		updki(ki[aa],bb-1);
	}
}
void updka(ll aa,ll bb)
{
	if(aa==0)return ;
	if(bb==0)KA=aa;
	else
	{
		//cout<<aa<<" "<<tbk<<"\n";
		masih--;
		b[aa]=te;
		updka(ka[aa],bb-1);
	}
}
int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)pos[a[i]]=i;
	for(i=2;i<=n;i++)ki[i]=i-1;
	for(i=1;i<n;i++)ka[i]=i+1;
	masih=n;
	tbk=n;
	while(masih)
	{
		masih--;
		te++;
		if(te==3)te=1;
		while(b[pos[tbk]])tbk--;
		//cout<<tbk<<"\n";
		b[pos[tbk]]=te;
		ll skr=pos[tbk];
		//cout<<skr<<"\n";
		KI=0;
		KA=0;
		updki(ki[skr],k);
		updka(ka[skr],k);
		if(KI!=0)ka[KI]=KA;
		if(KA!=0)ki[KA]=KI;
	}
	for(i=1;i<=n;i++)cout<<b[i];
	cout<<"\n";
}