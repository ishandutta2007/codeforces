#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,m;
ll ab(ll x){
	return x<0?-x:x;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>l>>r>>m;
		ll n,a;
		for(a=l;a<=r;a++){
			n=m/a;
			if(n>0&&ab(n*a-m)<=r-l)break;
			n++;
			if(ab(n*a-m)<=r-l)break;
		}
		ll cha=m-n*a;
		for(ll b=l;b<=r;b++){
			ll c=b-cha;
			if(c>=l&&c<=r){
				cout<<a<<' '<<b<<' '<<c<<endl;
				break;
			}
		}
	}
}