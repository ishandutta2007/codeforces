#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n,m,k;

LL gcd(LL x,LL y){
	if(!y) return x;
	return gcd(y,x%y);
}

int main(){
	cin>>n>>m>>k;
	LL temp=n*m*2;
	LL n0=n,m0=m;
	if(temp%k){
		puts("NO");
		return 0;
	}
	n*=2;
	LL k1=gcd(n,k),k2=k/k1;
	n/=k1; m/=k2;
	if(n>n0){
		n/=2;
		m*=2;
	}
	puts("YES");
	puts("0 0");
	cout<<"0 "<<m<<endl;
	cout<<n<<" 0"<<endl;
}