#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll h,m,H,D,C,N,sel,HT,i;
double h1,h2,he;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>h>>m;
	cin>>H>>D>>C>>N;
	h1=H/N;
	if(H%N!=0)
		h1++;
	if(h>=20)
		sel=0;
	else
	{
		sel=(20-h)*60;
		sel-=m;
	}
	HT=H;
	for(i=1;i<=sel;i++)
		HT+=D;
	h2=HT/N;
	if(HT%N!=0)
		h2++;
	h2=h2*8.0;
	h2=h2/10.0;
	he=min(h1,h2)*(double)C;
	cout<<fixed<<setprecision(4)<<he<<"\n";
}