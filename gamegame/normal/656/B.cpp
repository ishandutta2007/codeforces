#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(max(a,b),min(a,b));
}
bool a[720720];
int main(){
	int n;
	cin >> n;
	double nume=0,deno=1;
	int m[n+1],r[n+1];
	for(int i=1; i<=n ;i++){ cin >> m[i]; deno=lcm(deno,m[i]); }
	for(int i=1; i<=n ;i++){
		cin >> r[i];
		for(int j=r[i]; j<deno ;j+=m[i]) a[j]=true;
	}
	for(int i=0; i<deno ;i++) nume+=a[i];
	cout << nume/deno;
}