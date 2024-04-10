#include<iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	int ans=0;	
	while(a!=0){
		ans+=(a%8==1);
		a=a/8;
	}
	cout << ans << endl;
}