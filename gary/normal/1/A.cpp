#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a;
	scanf("%lld %lld %lld",&n,&m,&a);
	long long ans1,ans2;
	if(n%a!=0) ans1=n/a+1;
	else ans1=n/a;
	if(m%a!=0) ans2=m/a+1;
	else ans2=m/a;
	cout<<ans1*ans2<<endl;
}