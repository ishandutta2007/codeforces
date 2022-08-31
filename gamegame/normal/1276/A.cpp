#include<bits/stdc++.h>
using namespace std;
string s;
void solve(){
	cin >> s;
	s="xx"+s+"xx";
	vector<int>v;
	for(int i=0; i<s.size() ;i++){
		bool a1=(s[i]=='o' && s[i-2]=='t' && s[i-1]=='w');
		bool a2=(s[i]=='o' && s[i+2]=='e' && s[i+1]=='n');
		if(a1 && a2) v.push_back(i-1);
		else if(a1) v.push_back(i-2);
		else if(a2) v.push_back(i);
	}
	cout << v.size() << endl;
	for(auto cur:v) cout << cur << ' ';
	cout << endl; 
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}