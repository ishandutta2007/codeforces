#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,K,a[10005],t[10005];
ll sum(ll x,ll y){
	ll a,b;
	cout<<"or "<<x<<' '<<y<<'\n',fflush(stdout);
	cin>>a;
	//a=(t[x]|t[y]);
	cout<<"and "<<x<<' '<<y<<'\n',fflush(stdout);
	//b=(t[x]&t[y]);
	cin>>b;
	return a+b;
}
int main(){
	cin>>n>>K;
	//for(int i=1;i<=n;i++)cin>>t[i];
	ll x=sum(1,2),y=sum(2,3),z=sum(3,1);
	a[1]=(x+y+z)/2-y,a[2]=(x+y+z)/2-z,a[3]=(x+y+z)/2-x;
	for(int i=4;i<=n;i++)a[i]=sum(1,i)-a[1];
	sort(a+1,a+n+1),cout<<"finish "<<a[K]<<endl;
}