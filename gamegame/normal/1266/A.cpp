#include<bits/stdc++.h>
using namespace std;
string s;
string t;
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--){
		cin >> s;
		int sum=0;
		int even=0;
		int zero=0;
		for(auto cur:s){
			if(cur=='0') zero++;
			if(cur%2==0) even++;
			sum+=cur;
		}
		if(sum%3==0 && even>=2 && zero>=1) cout << "red\n";
		else cout << "cyan\n";
	}
}