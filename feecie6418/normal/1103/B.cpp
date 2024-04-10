#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int main() {
	while(1){
		string str;
		cin>>str;
		if(str!="start")return 0;
		ll x=1,y=2;
		while(1){
			cout<<"? "<<x<<' '<<y<<endl;
			cin>>str;
			if(str=="x")break;
			x*=2,y*=2;
		}
		if(x==1){
			cout<<"? "<<2<<' '<<1<<endl;
			cin>>str;
			if(str=="x")cout<<"! 1"<<endl;
			else cout<<"! 2"<<endl;
			continue;
		}
		ll l=x+1,r=y,ans=0;
		while(l<=r){
			ll mid=(l+r)/2;
			cout<<"? "<<x<<' '<<mid<<endl;
			cin>>str;
			if(str=="x")ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<"! "<<ans<<endl;
	} 
}