#include<iostream>
using namespace std;
int main(){
	long long n,a,b,c;
	cin >> n >> a >> b >> c;
	if(a<=b-c || n<b){
		cout << n/a;
	}
	else if(a<b){//ugly case
		cout << (n-c)/(b-c)+(n-(n-c)/(b-c)*(b-c))/a;
	}
	else{
		cout << (n-c)/(b-c);
	}
}