#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],b[100005],c[100005],d[100005]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)cin>>b[i],d[i]=b[i]-b[i-1];
	if(a[1]!=b[1]||a[n]!=b[n])return puts("No"),0;
	sort(c+2,c+n+1),sort(d+2,d+n+1);
	for(int i=2;i<=n;i++)if(c[i]^d[i])return puts("No"),0;
	puts("Yes");
	return 0;
}