#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a[100001];
int l,r;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	n=s.size();
	for(int i=0; i<n ;i++){
		if(s[i]!='0') break;
		l++;
	}
	r=n-1;
	for(int i=n-1; i>=0; i--){
		if(s[i]!='0') break;
		r--;
	}
	if(l==n){
		cout << "YES\n";
		return 0;
	}
	bool ok=true;
	for(int i=l; i<=r ;i++){
		if(s[i]!=s[r+l-i]) ok=false;
	}
	if(!ok){
		cout << "NO\n";
		return 0;
	}
	if(l>n-1-r) cout << "NO\n";
	else cout << "YES\n"; 
}