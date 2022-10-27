#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	string s; cin>>s;
	int n = s.size();
	s += s;
	int ans = 0;
	int cur = 1;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[i - 1])cur++;
		else cur = 1;
		ans = max(ans, cur);
	}
	cout<<min(ans, n);

	return 0;
}