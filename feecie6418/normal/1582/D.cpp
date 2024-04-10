#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n%2==0){
			for(int i=1;i<=n;i+=2)cout<<a[i+1]<<' '<<-a[i]<<' ';
			puts("");
			continue;
		}
		else {
			for(int i=1;i+3<n;i+=2)cout<<a[i+1]<<' '<<-a[i]<<' ';
			if(a[n-1]+a[n]!=0)cout<<a[n-1]+a[n]<<' '<<-a[n-2]<<' '<<-a[n-2];
			else if(a[n-1]+a[n-2]!=0)cout<<-a[n]<<' '<<-a[n]<<' '<<a[n-1]+a[n-2];
			else cout<<-a[n-1]<<' '<<a[n]+a[n-2]<<' '<<-a[n-1];
			puts("");
		}
	}
}