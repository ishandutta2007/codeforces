#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll i;
ll x[6],y[6],a[6],b[6],Xmi=1000,Xma=-1000,Ymi=1000,Yma=-1000,Ama=-1000,Ami=1000,Bma=-1000,Bmi=1000,sisi,tA,tB;
double jar(double aa,double bb,double cc,double dd)
{
	return ((aa-cc)*(aa-cc)+(bb-dd)*(bb-dd));
}
bool dalam(ll aa)
{
	if(Xmi<=a[aa]&&a[aa]<=Xma&&Ymi<=b[aa]&&b[aa]<=Yma)
		return 1;
	else
		return 0;
}
bool dalam2(ll aa)
{
	if(Ami<=x[aa]&&x[aa]<=Ama&&Bmi<=y[aa]&&y[aa]<=Bma)
	{
		if(x[aa]>=tA&&y[aa]>=tB&&jar(x[aa],y[aa],Ama,Bma)<jar(x[aa],y[aa],tA,tB))return 0;
		if(x[aa]>=tA&&y[aa]<=tB&&jar(x[aa],y[aa],Ama,Bmi)<jar(x[aa],y[aa],tA,tB))return 0;
		if(x[aa]<=tA&&y[aa]<=tB&&jar(x[aa],y[aa],Ami,Bmi)<jar(x[aa],y[aa],tA,tB))return 0;
		if(x[aa]<=tA&&y[aa]>=tB&&jar(x[aa],y[aa],Ami,Bma)<jar(x[aa],y[aa],tA,tB))return 0;
		return 1;
	}
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=1;i<=4;i++)
	{
		cin>>x[i]>>y[i];
		x[i]*=2;
		y[i]*=2;
		Xmi=min(Xmi,x[i]);
		Ymi=min(Ymi,y[i]);
		Xma=max(Xma,x[i]);
		Yma=max(Yma,y[i]);
	}
	for(i=1;i<=4;i++)
	{
		cin>>a[i]>>b[i];
		a[i]*=2;
		b[i]*=2;
		Ami=min(Ami,a[i]);
		Bmi=min(Bmi,b[i]);
		Ama=max(Ama,a[i]);
		Bma=max(Bma,b[i]);
	}
//	cout<<Ama<<" "<<Ami<<" "<<Bma<<" "<<Bmi<<"\n";
	tA=(Ama+Ami)/2.0;
	tB=(Bma+Bmi)/2.0;
	a[5]=tA;
	b[5]=tB;
	x[5]=(Xma+Xmi)/2;
	y[5]=(Yma+Ymi)/2;
//	cout<<sisi<<" "<<tA<<" "<<tB<<"\n";
	for(i=1;i<=5;i++)
		if(dalam(i))
		{
			cout<<"YES\n";
			return 0;
		}
	for(i=1;i<=5;i++)
		if(dalam2(i))
		{
			cout<<"YES\n";
			return 0;
		}
	cout<<"NO\n";
}