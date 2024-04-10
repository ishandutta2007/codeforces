#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ansn=1e18;
int main(){
	cin>>n;
	for (int i=1;i<=n*2;i++)cin>>a[i];
	sort(a+1,a+n+n+1);
	ansn=min(ansn,(a[n]-a[1])*(a[n+n]-a[n+1]));
	for (int i=2;i<=n;i++){
		ansn=min(ansn,(a[i+n-1]-a[i])*(a[n+n]-a[1]));
	}
	cout<<ansn<<endl;
	return 0;
}