#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	char mi='z'+1;
	for(auto c:s){
		if(c<=mi) cout << "Mike\n";
		else cout << "Ann\n";
		mi=min(mi,c);
	}
}