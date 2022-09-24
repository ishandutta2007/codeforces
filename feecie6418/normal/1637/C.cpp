#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005];
void Solve(){
	cin>>n;
	int fl1=0,fl2=0,cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll S=0;
	for(int i=2;i<n;i++){
		if(a[i]>1)fl1=1;
		if(a[i]%2==0)fl2=1;
		else cnt++;
		S+=a[i];
	}
	if(!fl1)return puts("-1"),void();
	if(n==3&&!fl2)return puts("-1"),void();
	cout<<(S+cnt)/2<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--){
		Solve();
	}
}