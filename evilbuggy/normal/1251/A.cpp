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

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		set<char> a;
		char ch = s[0];
		int p = 1;
		for(int i = 1; i < s.size(); i++){
			if(ch == s[i]){
				p++;
			}else{
				if(p&1)a.insert(ch);
				p = 1;
				ch = s[i];
			}
		}
		if(p&1){
			a.insert(ch);
		}
		for(auto x : a){
			cout<<x;
		}
		cout<<endl;
	}

	return 0;
}