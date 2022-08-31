#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
string u;
bool check(){
	u="";
	for(int i=0; i<n ;i++){
		if(t[i]=='1') u+=s[i];
	}
	for(int i=0; i<n ;i++){
		if(t[i]=='2') u+=s[i];
	}
	for(int i=1; i<n ;i++){
		if(u[i]<u[i-1]) return false;
	}
	return true;
}
void solve(){
	cin >> n >> s;
	t=s;
	for(int i=0; i<10 ;i++){
		int hv=0;
		for(int j=0; j<n ;j++){
			if(s[j]<i+48) t[j]='1';
			else if(s[j]>i+48) t[j]='2',hv=true;
			else if(hv) t[j]='1';
			else t[j]='2';
		}
		if(check()){
			cout << t << '\n';
			return;
		}
	}
	cout << "-\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}