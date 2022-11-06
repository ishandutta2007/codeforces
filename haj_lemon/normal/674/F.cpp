#include<bits/stdc++.h>
#define ll unsigned int
#define pb push_back
#define vll vector<ll>
using namespace std;
vll b;
ll n,p,q,ans;
vll operator *(vll x,vll y){
	vll z;z.clear();for (int i=0;i<=p;i++)z.pb(0);
	for (int i=0;i<=p;i++)
		for (int j=0;i+j<=p;j++)z[i+j]+=x[i]*y[j];
	return z;
}
vector<ll> po(ll x){
	vll y;y.clear();y.pb(1);for (int i=1;i<=p;i++)y.pb(0);
	vll z;z.clear();z.pb(1);z.pb(1);for (int i=2;i<=p;i++)z.pb(0);
	while (x){if (x%2)y=y*z;z=z*z;x/=2;}
	return y;
}
int main(){
	cin>>n>>p>>q;
	b=po(n);
	if (n<=p)b[n]=0;
	for (int i=b.size();i<=p;i++)b.push_back(0);
	for (int i=1;i<=q;i++){
		ll x=i,su=0;
		for (int j=0;j<=p;j++){su+=x*b[j];x=x*i;}
		ans=ans^su;
	}
	cout<<ans<<endl;
	return 0;
}