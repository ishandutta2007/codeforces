#include<bits/stdc++.h>
using namespace std;
long long x,y,p,q,f;
long long gcd(long long x,long long y){
	if (x%y==0) return y;return gcd(y,x%y);
}
int main(){
	cin>>x>>y>>p>>q;
	f=gcd(p,q);p/=f;q/=f;
	cout<<min(x/p,y/q)<<endl;
	return 0;
}