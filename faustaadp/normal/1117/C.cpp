#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll X1,X2,Y1,Y2,X,Y,Xa,Ya,has,i,n;
char a[101010];
ll bisa(ll aa,ll bb,ll cc)
{
	if((abs(aa)+abs(bb))<=cc)
	{
		has=min(has,cc);
		return 1;
	}
	else return 0;
}
ll cek(ll aa)
{
	ll Xb=X+Xa*aa,Yb=Y+Ya*aa;
	ll ii,H=aa*n;
	//cout<<aa<<" "<<Xb<<" "<<Yb<<"\n";
	for(ii=1;ii<=n;ii++)
	{
		H++;
		if(a[ii]=='U')Xb--;
		if(a[ii]=='D')Xb++;
		if(a[ii]=='R')Yb--;
		if(a[ii]=='L')Yb++;
		//cout<<H<<" "<<Xb<<" "<<Yb<<"  "<<abs(Xb)+abs(Yb)<<"\n";
		if(bisa(Xb,Yb,H))return 1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
	cin>>Y1>>X1;
	cin>>Y2>>X2;
	X=X2-X1;
	Y=Y2-Y1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='U')Xa--;
		if(a[i]=='D')Xa++;
		if(a[i]=='R')Ya--;
		if(a[i]=='L')Ya++;
	}
	//cout<<X<<" "<<Y<<" "<<Xa<<" "<<Ya<<"\n";
	has=1e18;
	cek(0);
	ll L=0,R=10000000000,C;
	while(L<=R)
	{
		C=(L+R)/2;
		if(!cek(C))
			L=C+1;
		else
			R=C-1;
	}
	if(has==1e18)has=-1;
	cout<<has<<"\n";
}