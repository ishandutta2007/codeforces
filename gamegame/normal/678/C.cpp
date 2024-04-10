#include<iostream>
using namespace std;
long long gcd2(long long a,long long b){
	if(b==0) return a;
	return gcd2(b,a%b);
}
long long gcd(long long a,long long b){
	return gcd2(max(a,b),min(a,b));
}
long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}
int main(){
	long long n,a,b,p,q;
	long long ac,bc,cc;
	cin >> n >> a >> b >> p >> q;
	ac=n/a;
	bc=n/b;
	cc=n/lcm(a,b);
	if(p<q){
		cout << ac*p+bc*q-cc*p;
	}
	else{
		cout << ac*p+bc*q-cc*q;
	}
}