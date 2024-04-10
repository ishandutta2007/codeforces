#include<iostream>
#include<vector>
using namespace std;
bool a[26];
int main(){
	ios::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	if(n>26){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<n ;i++){
		a[s[i]-97]=true;
	}
	for(int i=0; i<26 ;i++){
		if(a[i]) n--;
	}
	cout << n;
}