#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

string rem(string &s){
	string ret = "";
	for(auto ch : s){
		if(ch != 'a')ret += ch;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string t;
	cin>>t;
	int n = t.size();
	string ss = rem(t);

	int m = ss.size();
	if(m&1){
		cout<<":("<<endl;
		return 0;
	}
	m >>= 1;
	string a = ss.substr(0, m);
	string b = ss.substr(m, m);
	if(a != b){
		cout<<":("<<endl;
		return 0;
	}

	for(int i = 0; i < m; i++){
		if(t[n-m+i] != a[i]){
			cout<<":("<<endl;
			return 0;
		}
	}
	cout<<t.substr(0, n-m)<<endl;

	return 0;
}