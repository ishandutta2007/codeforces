#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	string s; cin>>s;
	if(n == 1){
		cout<<"Yes";
		exit(0);
	}
	vector<int> f(26);
	for(auto ch : s){
		f[ch - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(f[i] > 1){
			cout<<"Yes";
			exit(0);
		}
	}
	cout<<"No";

	return 0;
}