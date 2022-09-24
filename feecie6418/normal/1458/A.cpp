#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],b[200005],t[200005];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	if(n==1){
		for(int i=1;i<=m;i++)cout<<a[1]+b[i]<<' ';
		return 0;
	}
	for(int i=1;i<n;i++)t[i]=a[i+1]-a[i];
	ll g=t[1];
	for(int i=2;i<n;i++)g=__gcd(g,t[i]);
	for(int i=1;i<=m;i++)cout<<__gcd(a[1]+b[i],g)<<' ';
}