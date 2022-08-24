#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
string s;
string t;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	bool ok=false;
	for(int i=0; i<5 ;i++){
		cin >> t;
		if(s[0]==t[0] || s[1]==t[1]) ok=true;
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}