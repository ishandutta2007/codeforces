#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k,a,b,c,d;
	cin >> n >> k >> a >> b >> c >> d;
	if(n==4 | k<=n){
		cout << -1 << '\n';
		return 0;
	}
	cout << a << ' ' << c << ' ';
	for(int i=1; i<=n ;i++){
		if(i!=a && i!=b && i!=c && i!=d) cout << i << ' ';
	}
	cout << d << ' ' << b << endl;
	cout << c << ' ' << a << ' ';
	for(int i=1; i<=n ;i++){
		if(i!=a && i!=b && i!=c && i!=d) cout << i << ' ';
	}
	cout << b << ' ' << d << endl;
	
}