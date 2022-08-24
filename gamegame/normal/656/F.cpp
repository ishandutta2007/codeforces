#include<iostream>
using namespace std;
int main(){
	string n;
	cin >> n;
	int ans=1;
	for(int i=1; i<=6 ;i++){
		if(n[i]=='0'){
			ans+=9;
		}
		else{
			ans+=n[i]-48;
		}
	}
	cout << ans << endl;
}