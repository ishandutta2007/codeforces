#include<iostream>
using namespace std;
string s;
bool check(int st,int en){
	for(int i=st; i<=en ;i++){
		if(s[i]!=s[en+st-i]) return true;
	}
	return false;
}
int main(){
	cin >> s;
	int ans=0;
	for(int i=0; i<s.size() ;i++){
		for(int j=i; j<s.size() ;j++){
			if(check(i,j)) ans=max(ans,j-i+1);
		}
	}
	cout << ans << endl;
}