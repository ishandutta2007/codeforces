#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(c==0){
		if(a==b) cout << "YES\n";
		else cout << "NO\n";
	}
	else if((a%c+c)%c==(b%c+c)%c){
		if(a<=b && c>0 || a>=b && c<0){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	else cout << "NO\n";
}