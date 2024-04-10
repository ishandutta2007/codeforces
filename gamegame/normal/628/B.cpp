#include<iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	long long int ans=0;
	for(int i=0; i<s.size() ;i++){
		ans+=(s[i]%4==0);
	}
	for(int i=1; i<s.size() ;i++){
		if(((s[i-1]-48)*10+s[i]-48)%4==0){
			ans+=i;
		}
	}
	cout << ans << endl;
}