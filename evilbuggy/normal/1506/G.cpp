#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

char process(string &s){
	vector<int> freq(26);
	for(auto ch : s){
		freq[ch - 'a']++;
	}
	int n = s.size();
	int ind = 0;
	for(int i = 0; i < n; i++){
		if(s[i] > s[ind])ind = i;
		if(freq[s[i] - 'a'] == 1)break;
		freq[s[i] - 'a']--;
	}
	char ret = s[ind];
	string ns = "";
	for(int i = ind + 1; i < n; i++){
		if(s[i] != s[ind])ns += s[i];
	}
	s = ns;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		while(!s.empty()){
			cout << process(s);
		}
		cout << '\n';
	}

	return 0;
}