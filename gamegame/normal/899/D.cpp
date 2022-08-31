#include<iostream>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n<=4){
		cout << n*(n-1)/2 << endl;
		return 0;
	}
	ll x=5,y;
	while(x*10<=n){
		x*=10;
	}
	y=2*x;
	ll num1=n/y,num2=n%y,num3;
	num3=min(num2,y-2);
	ll ans=0;
	if(num3<x){
		ans=(num1+1)*num1*num3+(x-num3-1)*num1*num1;
	}
	else{
		ans=(num1+1)*(num1+1)*(num3-x+1)+(num1+1)*num1*(y-num3-2);
	}
	if(num2<=y-2) ans+=num1*num1;
	else if(num2==y-1) ans+=(num1+1)*num1;
	cout << ans << endl;
}