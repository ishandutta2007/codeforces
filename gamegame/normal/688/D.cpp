#include<iostream>
using namespace std;
long long gcd2(long long a,long long b){
	if(b==0) return a;
	return gcd2(b,a%b);
}
long long lcm2(long long a,long long b){
	return a*b/gcd2(a,b);
}
long long lcm(long long a,long long b){
	return lcm2(max(a,b),min(a,b));
}
long long gcd(long long a,long long b){
	return gcd2(max(a,b),min(a,b));
}
int main(){
	ios::sync_with_stdio(false);
	int n,k,tmp;
	cin >> n >> k;
	int ans=1;
	for(int i=1; i<=n ;i++){
		cin >> tmp;
		ans=lcm(ans,gcd(tmp,k));
	}
	if(ans==k) cout << "Yes\n";
	else cout << "No\n";
}