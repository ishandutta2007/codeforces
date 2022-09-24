#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n;
ll a[30005],b[30005],c[30005];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1)return puts("YES"),void();
	b[1]=a[1],c[1]=0;
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1])b[i]=b[i-1]+a[i]-a[i-1],c[i]=c[i-1];
		else c[i]=c[i-1]+a[i]-a[i-1],b[i]=b[i-1];
		if(b[i]<0||c[i]<0)return puts("NO"),void();
	}
	puts("YES");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
    return 0;
}