#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,x;
ll co(ll x){int y=0;while (x){y+=x%10;x/=10;}return y;}
int main(){
	cin>>n;
	while (x<=n){
		x=x*10+9;
	}
	x/=10;
	cout<<co(x)+co(n-x)<<endl;
	return 0;
}