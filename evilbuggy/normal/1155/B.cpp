#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	string s;
	cin>>n>>s;
	int k = (n-11)/2;
	string t = "";
	for(auto ch : s){
		if(ch != '8'){
			if(k == 0)t += ch;
			else k--;
		}else{
			t += ch;
		}
	}
	k = (n-11)/2;
	s = t;
	t = "";
	for(auto ch : s){
		if(ch == '8'){
			if(k == 0)t += ch;
			else k--;
		}else{
			t += ch;
		}
	}
	if(t[0] == '8'){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}