#include<iostream>
using namespace std;
int n,k;
int ans;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ans=k;
	for(int i=1; i<=n ;i++){
		int a;
		cin >> a;
		ans=gcd(a,ans);
	}
	cout << k/ans << endl;
	for(int i=0; i<k/ans ;i++){
		cout << ans*i << ' ';
	}
	cout << endl;
}