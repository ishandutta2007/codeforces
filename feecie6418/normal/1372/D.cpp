#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005];
ll mx=0,s1[200005],s2[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s1[i]=s1[max(i-2,0)]+a[i];
	for(int i=n;i>=1;i--)s2[i]=s2[i+2]+a[i];
	for(int i=1;i<=n;i++)mx=max(mx,s1[i]+s2[i+1]);
	cout<<mx;
}