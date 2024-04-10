#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Query(ll l,ll r){
	cout<<"? "<<l<<' '<<r<<endl;
	ll ret;
	cin>>ret;
	return ret;
}
void Solve(){
	int n;
	cin>>n;
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		ll w=Query(mid,n);
		if(!w)ans=mid,r=mid-1;
		else l=mid+1;
	}
	int I,J,K=ans;
	ll w1=Query(1,K),w2=Query(1,K-1);
	J=K-(w1-w2);
	w1=Query(1,J-1),w2=Query(1,J-2);
	I=J-1-(w1-w2);
	cout<<"! "<<I<<' '<<J<<' '<<K<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}